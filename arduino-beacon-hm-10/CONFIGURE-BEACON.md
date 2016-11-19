# Criando um beacon com o sensor HM-10

## Componentes necessários

- Arduino
- Protoboard
- Sensor Bluetooth 4.0 **HM-10** ([Link](https://www.itead.cc/serial-port-ble-module-master-slave-hm-10.html))

## Esquematização

![Esquematização HM-10 -> Arduino](hm-10-schematics_bb.png)

## Desenvolvimento

Antes de qualquer coisa, é necessário realizar as conexões com o sensor HM-10 de acordo com a esquematização acima, se tudo estiver de acordo, você pode copiar o [código](/arduino-beacon-hm-10/arduino-code/arduino-code.ino) presente na pasta deste documento.

Existem dois métodos já prontos, que inicialmente vamos abordar apenas um, o método *detectBleBaudRate*, que é responsável por identificar e te informar a **taxa de transmissão** que o sensor HM-10 trabalha. Ele vai iterar as taxas de transmissões principais primeiramente, e logo em seguida caso não seja uma delas, ele itera as outras menos prováveis.

Esta taxa de transmissão serve para que o Arduino consiga *conversar* na mesma língua que o sensor, e todos os comandos sejam reconhecidos e traduzidos pelo sensor.

**Nota:** Não vamos abordar o passo a passo de como realizar toda a configuração do Arduino, como ligá-lo, como compilar o código e como utilizar o monitor serial dele. Isso é um outro foco, mas caso precisem de ajuda, não hesitem em abrir issues. Para mais informações, você pode verificar o tutorial abaixo:

- [Getting Started - arduino.cc](https://www.arduino.cc/en/Guide/HomePage)

----

Quando estiver com o código em mãos, compile-o para o Arduino e ele estará aguardando seus comandos. Como foi citado, cada sensor quando é comprado, vem com uma taxa de transmissão não estabelecida pelo fabricante. Portanto, no *serial monitor* do Arduino, escreva **detect** e envie para o Arduino. As informações de resposta a seguir devem ser mostradas:

```c
-----------------------------
Serial sent: detect
-----------------------------
Detecting BLE baud rate:
Checking baud rate: 9600
-----------------------------
BLE Baud Detected: 9600
-----------------------------
```

A iteração inicia a partir da linha **Detecting BLE baud rate** e itera cada taxa já estabelecida na *linha 13* do código. Assim que encontrada, haverá um separador e retornará **BLE Baud Detected: xxxx**. O número presente de taxa, deve ser então alterado nas *linhas 57 e 58* e compilar novamente o código ao Arduino.

Dependendo de qual foi a taxa recebida, altere no seu *serial monitor* a taxa correspondente e vamos começar a programar o sensor para que ele se torne um beacon.

Assim que o código for compilado, envie um comando **AT** através do *serial monitor* e ele responderá com um **OK** se estiver tudo certo. Exemplo de resposta:

```c
-----------------------------
Serial sent: AT
mySerial received: OK
-----------------------------
```

Você também pode verificar qual a versão do firmware do seu sensor, através do comando **AT+VERR?** e deve receber uma resposta semelhante:

```c
-----------------------------
Serial sent: AT+VERR?
mySerial received: HMSoft V533
-----------------------------
```

A versão do firmware recomendada são as versões 500+. Caso ele retorne uma informação inferior a esta versão, recomendo a leitura deste outro _documento_.

----

Se a comunicação do Arduino com o sensor estiver funcional, vamos seguir em frente. Execute os comandos a seguir:

```c
// Restaura o sensor para os padrões de fábrica
AT+RENEW
// Reinicia o sensor, para que os padrões sejam de fato atualizados
AT+RESET
```

Recomendados que o comando **detect** seja enviado novamente, já que como os padrões de fábrica são restaurados, a **taxa de transmissão** também pode ser alterada.

Assim que o sensor for reiniciado, sugiro o envio do comando **AT** para ver se está tudo **OK** antes de continuarmos. Se sim, abaixo seguem os próximos comandos.

```c
// Define o valor hexadecimal "major" do sensor
AT+MARJ0xNNNN
// Define o valor hexadecimal "minor" do sensor
AT+MINO0xNNNN
``` 

###O que são os valores *major* e *minor*?

Como as traduções se referem, elas trazem informações maiores e menores do sensor. Estas informações são especialmente importantes para as aplicações para as quais este sensor está sendo configurado.

Imagine que o valor maior (major) é um identificador único de um estabelecimento, definimos o valor como **1**, portanto, devemos escrever **AT+MARJ0x0001** que em hexadecimal equivale ao número 1.

Já o valor menor, equivale as seções dentro daquele estabelecimento. Geralmente, em exemplos práticos, isso é usado em varejos quando você quer ter 5 beacons em uma prateleira, em que cada um tem um valor menor (minor) referente a uma marca daquela prateleira. Vamos supor que queremos o valor **43522**, portanto, devemos escrever **AT+MINO0xAA02** que em hexadecimal equivale ao número 43522.

Com isso, estes valores *minors* e *majors* são inteiramente utilizados para identificar o seu beacon dentro do seu aplicativo ou software, junto com o **UUID** do mesmo. **Estes valores devem ser especificados em hexadecimal**.

Para identificar o valor *major* e *minor* atual do beacon, utilize os comandos abaixo:

```c
// Identifica o valor "major" do sensor
AT+MARJ?
// Identifica o valor "minor" do sensor
AT+MINO?
```

----

O próximo passo é definir um nome para o nosso sensor, para no caso de distribuição em larga escala, isso é importante para identificação e alteração do mesmo. Abaixo, comandos para definir e identificar o nome do mesmo:

```c
// Define um nome para o beacon
AT+NAMEMeuBeacon
// Identifica o nome do beacon
AT+NAME?
```

----

Os comandos a seguir a serem enviados através do *serial monitor* referem-se totalmente a transformação do sensor em um beacon de fato. Tirando todas as funções de bluetooth comum e trazendo a tona sua funcionalidade de consumo baixo de energia e envio de dados constante.

```c
// Define o padrão de envio de status
// (Valor 5 corresponde a 546.25 millisegundos)
AT+ADVI5 // Define o padrão de envio de status

// Configura o sensor como não pareável
AT+ADTY3

// Habilita o modo beacon do sensor  
AT+IBEA1

// Configura o sensor para apenas emitir sinais 
AT+DELO2

// Habilita o modo auto-sleep, para economizar energia  
AT+PWRM0 
```

Assim que todas as informações foram enviadas para o sensor, ele tornou-se um beacon funcional. Para conseguir utilizá-lo agora como beacon, o sensor deve ser reiniciado através do comando:

```c
AT+RESET
```

Assim que reiniciado, não será mais possível enviar comandos para ele através do Arduino, devido a informarmos para ele entrar em *modo soneca* literalmente, com o comando **AT+PWRM0**.

Para verificar se o seu sensor realmente tornou-se um beacon, você pode baixar aplicativos que identificam beacons e te mostram o mesmo. Recomendamos o uso do aplicativo recentemente lançado no [Android](https://play.google.com/store/apps/details?id=net.alea.beaconsimulator&hl=pt_BR)

###Quero voltar a enviar comandos para o sensor, como faço?

Para enviar comandos novamente para o sensor, temos o nosso segundo método citado anteriormente, chamado *wakeUp*. Para utilizá-lo, basta conectar o sensor ao Arduino com a esquematização especificada e através do *serial monitor* enviar o comando **wake**. Ele vai nos retornar as mensagens a seguir:

```c
-----------------------------
Serial sent: wake
-----------------------------
Wake up command has been sent to HM-10
-----------------------------
```

Assim que enviado, o sensor deve começar a piscar novamente e está pronto para receber comandos. Teste o comando **AT** para verificar se ele retorna um **OK** e você pode fazer as alterações que desejar.

----

###Qual o próximo passo?

Futuramente, vamos descrever neste repositório exemplos de como desenvolver um aplicativo híbrido para Android e iOS e também nativo. Além disso, também temos algumas informações adicionais que em breve preencheremos com conteúdo.

- Entendimento e alteração do UUID
- Alterando a potência do meu beacon
- Preparando o beacon para distribuição

### Links de referência

- [Beacon como dispositivo central](http://blog.blecentral.com/2015/05/13/hm-10-central-ibeacon)
- [HM-10 as iBeacon (PDF)](https://drive.google.com/open?id=0B6UMNMtHS_pYWHpBalh4Y2U2SFU)
- [Bluetooth 4.0 BLE Module HM-10 (PDF)](https://drive.google.com/file/d/0B6UMNMtHS_pYT0V2dEswZ1ctd3M/view?usp=sharing)

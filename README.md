# Beacons

O propósito deste repositório é centralizar todo um estudo em cima da tecnologia beacon e o que ela oferece. Além de mostrar as infinitas possibilidades de criação e uso. 

## Introdução

Beacon é uma tecnologia utilizada para enviar notificações em ambientes fechados e mais próximos do que GPS. O GPS hoje nos informa de forma geral onde estamos, mas não consegue saber exatamente o quão perto ou longe estamos dentro de um prédio. Para isso, os beacons foram criados para solucionar problemas de proximidade e interações com usuário de acordo com o comportamento deles.

Ele também é um termo referente a tecnologia **BLE**, que sua sigla significa *Bluetooth Low Energy*, uma tecnologia criada e anunciada pelo Bluetooth em sua versão 4.0. Ela proporciona ao bluetooth uma distribuição mais escalável devido ao tamanho do sensor, potência possível de ser alcançada e consumo menor de bateria relacionado as versões anteriores do mesmo.

A nomenclatura **beacon** relacionado a tecnologia *BLE* surgiu de um anúncio da Apple em 2013 sobre a denominação deles como *iBeacon* devido a adaptação do Bluetooth Low Energy nas versões mais novas do iPhone. Com isso, o Bluetooth Low Energy ficou conhecido como beacon (em sua tradução, como farol).

Com o lançamento da nova versão do Bluetooth, o mercado de IoT cresceu em cima da tecnologia de baixo consumo, já que ela serve para emissão de dados e com esta emissão de dados podem ser exploradas infinitas possibilidades relacionadas a Internet das Coisas.

## Criação e montagem de um beacon (DIY)

Para a criação e montagem de um beacon, podemos utilizar um microcontrolador como o **Arduino** no qual nos oferece uma facilidade de envio de comandos para os sensores Bluetooth Low Energy. Utilizaremos aqui, o sensor [HM-10](https://www.itead.cc/serial-port-ble-module-master-slave-hm-10.html) que é um dos sensores que possui um firmware mais recente e possui comandos próprios para ser configurado como beacon.

Descrevemos a montagem e criação do mesmo neste [link](/beacon-hm-10/CONFIGURE-BEACON.md).

## Beacon Monitoring & Ranging

Existem dois tipos de ações possíveis de serem executadas com os beacons. São elas chamadas de **monitoring** e **ranging**. Estas ações são utilizadas para determinar qual será o comportamento daquele beacon na aplicação que está configurada.

### Beacon Monitoring

O comportamento de *Monitoring* ocorre quando o seu aplicativo entra ou sai de dentro do alcance do beacon, o aplicativo pode estar suspendido ou encerrado, dependendo apenas do Bluetooth ligado.

**Normalmente, esse comportamento é utilizado para lançar push notifications automáticas**

### Beacon Ranging

O comportamento de *Ranging* que a tecnologia beacon oferece, é utilizada com o aplicativo aberto e serve justamente para lançar determinadas ações de acordo com a distância que você está do beacon. **Utilizado na maior parte das vezes em lojas de varejos, para que o beacon possa notificar que você está perto de um sapato em promoção.**

### Observações

- Beacon Ranging em celulares iPhones funciona apenas com o aplicativo aberto;
- Os resultados de sinais entre o dispositivo e o beacon podem variar de acordo com o local do mesmo. Se ele estiver em uma bolsa ou bolso, o resultado pode variar bastante, sendo recomendado a colocação do beacon em um local livre de interrupções.

## Tecnologias complementares

### Geofencing

Geofencing de uma maneira bem simples, é uma tecnologia utilizada em conjunto com *GPS* ou *RFID* para definir limites de alcance, como um perímetro. Muito utilizado em serviços de entrega para saber quando o entregador sai da sua rota.

## Referências

- [Bluetooth Low Energy (BLE) Beacon Monitoring (Detection, Location, and Reporting)](http://blogs.cisco.com/wireless/bluetooth-low-energy-ble-beacon-monitoring-detection-location-and-reporting)
- [What are region Monitoring and Ranging?](https://community.estimote.com/hc/en-us/articles/203356607-What-are-region-Monitoring-and-Ranging-)

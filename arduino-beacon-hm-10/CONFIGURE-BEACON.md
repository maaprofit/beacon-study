# Criando um beacon com o sensor HM-10

## Componentes necessários

- Arduino
- Protoboard
- HM-10
- Bateria Lithium CR2032 (para distribuição)

## Esquematização

![Esquematização HM-10 -> Arduino](hm-10-schematics_bb.png)

## Desenvolvimento

## Lista de comandos para tornar o sensor em um Beacon

```c
AT+RENEW // Reseta o módulo para os padrões de fábrica  
AT+RESET // Reinicia o HM-10  
AT // Comando que retorna se existe comunicação  
AT+MARJ0xnnnn // Define o valor "major" do beacon (hexadecimal)  
AT+MINO0xnnnn // Define o valor "minor" do beacon (hexadecimal)  
AT+ADVI5 // Define o padrão de envio de status (Valor 5 corresponde a 546.25 millisegundos)  
AT+NAMEMyiBeacon // Define um nome para o beacon  
AT+ADTY3 // Configura o dispositivo como não pareáve/l  
AT+IBEA1 // Habilita o modo beacon  
AT+DELO2 // Configure o beacon para apenas emitir sinais  
AT+PWRM0 // Habilita o auto-sleep para economizar energia  
AT+RESET // Reinicia o módulo
```

### Links de referência

- [Beacon como dispositivo central](http://blog.blecentral.com/2015/05/13/hm-10-central-ibeacon)
- [HM-10 as iBeacon (PDF)](https://drive.google.com/open?id=0B6UMNMtHS_pYWHpBalh4Y2U2SFU)
- [Bluetooth 4.0 BLE Module HM-10 (PDF)](https://drive.google.com/file/d/0B6UMNMtHS_pYT0V2dEswZ1ctd3M/view?usp=sharing)

## Configuração HM-10 - iBeacon

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

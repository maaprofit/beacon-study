## Configuração HM-10 - iBeacon

´´´c
AT+RENEW  //Reset the module to the original factory settings  
AT+RESET  //Restart the module  
AT  //Resend this command until the module is ready and answers OK  
AT+MARJ0xnnnn  //Define the Major value of the iBeacon (hexadecimal)  
AT+MINO0xnnnn  //Define the Minor value of the iBeacon (hexadecimal)  
AT+ADVI5  //Define the advertising interval (Value 5 corresponds to 546.25 milliseconds)  
AT+NAMEMyiBeacon  //Define the device/iBeacon name (choose a unique value)  
AT+ADTY3  //Configure the device as non-connectable  
AT+IBEA1  //Enable iBeacon mode  
AT+DELO2  //Configure iBeacon as broadcast only  
AT+PWRM0  //Enable auto-sleep to reduce energy consumption  
AT+RESET  //Restart the module
´´´
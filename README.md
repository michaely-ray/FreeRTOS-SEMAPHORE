# FreeRTOS-SEMAPHORE
#
# O código deve criar na app_main uma task que chama duas funções, Init Wifi e Init  MQTT. Na função Init Wifi é criada outra task, a HandleWifi que indicará o Get IP e sinalizará para a função Init MQTT inicializar.  
# A função do MQTT só deverá ocorrer quando a HandleWifi finalizar.
#
#

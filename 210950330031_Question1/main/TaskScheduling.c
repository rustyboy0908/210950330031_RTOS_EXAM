#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

//General Variables used
TaskHandle_t xHandleTaskLog;
TaskHandle_t xHandleTaskLog2;
TaskHandle_t xHandleTaskLog3;
TaskHandle_t xHandleTaskLog4;
TaskHandle_t xHandleTaskLog5;
BaseType_t result;
BaseType_t result2;
BaseType_t result3;
BaseType_t result4;
BaseType_t result5;
BaseType_t SendStatus;
BaseType_t RecStatus;
QueueHandle_t msg;

//TASK Declaration
void T1(void * arg);
void T2(void * arg);
void T3(void * arg);
void T5(void * arg);
void T4(void * arg);

void app_main()
{
    printf("Inside Main\n");

//Queue Create of Size int and Entries allowed is 10.
    msg = xQueueCreate( 10, sizeof(int));
  	if(msg == NULL)
  	{
  		 perror("Error");
  	}
//Task 1
    result = xTaskCreate(T1,"T1",2048,NULL,5,&xHandleTaskLog);
    if (result == pdPASS)
    {
        printf("Task1 Created!\n");
    }
//Task 2
   result2 = xTaskCreate(T2,"T2",2048,NULL,6,&xHandleTaskLog2);
    if (result2 == pdPASS)
    {
        printf("Task2 Created\n");
    }
//TAsk 3
    result3 = xTaskCreate(T3,"T3",2048,NULL,7,&xHandleTaskLog3);
    if (result2 == pdPASS)
    {
        printf("Task3 Created\n");
    }
//Task4
    result4 = xTaskCreate(T4,"T4",2048,NULL,8,&xHandleTaskLog4);
    if (result4 == pdPASS)
    {
        printf("Task4 Created\n");
    }
//Task5
    result5 = xTaskCreate(T5,"T5",2048,NULL,9,&xHandleTaskLog5);
    if (result5 == pdPASS)
    {
        printf("Task5 Created\n");
    }


}

//All task definition begins

void T1(void * arg)
{
     UBaseType_t stackSize;
    while(1)
    {
    printf("Inside T1--StackSize> ");
    stackSize = uxTaskGetStackHighWaterMark(NULL);
    printf("%d\n",stackSize);
    vTaskDelay(pdMS_TO_TICKS(1000));
    }
    //vTaskDelete(xHandleTaskLog);
}

void T2(void * arg)
{
    UBaseType_t stackSize;

    while(1)
    {
    printf("Inside T2--StackSize> ");
    stackSize = uxTaskGetStackHighWaterMark(NULL);
    printf("%d\n",stackSize);
    vTaskDelay(pdMS_TO_TICKS(2000));
    }
    //    vTaskDelete(xHandleTaskLog2);
}

void T3(void * arg)
{
    UBaseType_t stackSize;

    while(1)
    {
    printf("Inside T3--StackSize> ");
    stackSize = uxTaskGetStackHighWaterMark(NULL);
    printf("%d\n",stackSize);
    vTaskDelay(pdMS_TO_TICKS(5000));
    }
    //    vTaskDelete(xHandleTaskLog2);
}

void T4(void * arg)
{
    UBaseType_t stackSize;
    uint32_t data= 420;
    while(1)
    {
    printf("Inside T4--StackSize> ");
    stackSize = uxTaskGetStackHighWaterMark(NULL);
    printf("%d\n",stackSize);
    SendStatus= xQueueSend(msg,&data,(TickType_t)10);
	printf("Sending2 Task done ---> %d\n", data);
    vTaskDelay(pdMS_TO_TICKS(1000));
    }
    //    vTaskDelete(xHandleTaskLog2);
}

void T5(void * arg)
{
    UBaseType_t stackSize;
    uint32_t RData;
    while(1)
    {
    printf("Inside T5--StackSize> ");
    stackSize = uxTaskGetStackHighWaterMark(NULL);
    printf("%d\n",stackSize);

    RecStatus= xQueueReceive(msg, &RData,( TickType_t ) 10);
	printf("Data Receiver --->%d:\n",RData);
    vTaskDelay(pdMS_TO_TICKS(1000));
    }
    //    vTaskDelete(xHandleTaskLog2);
}



 

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   struct timeval startTime, endTime;
    FILE * fp = NULL;
    int size = 1920 *1080 * 3;
    char inputFileName[] = "wpinyuv1920x1080.yuv";
    fp = fopen(inputFileName, "r+b");
    if(NULL == fp)
    {
        printf("fopen() Error!!!\n");
    }

    //Allocate Buffer for rawData
    unsigned char * rawData = NULL;
    rawData = (unsigned char *)malloc(size);
    if (NULL == rawData) {
        printf("Rawdata is NULL\n");
    }
    if(!fp)
    fread(rawData, size, 1, fp);
    int memcpycount,i=0;
    printf("enter no.of iterations for memcpy");
    scanf("%d",&memcpycount);
    while(i<memcpycount)
    {
        unsigned char* dstptr = (unsigned char *)malloc(size);
        /*measure the memcpy time start**/
        //std::chrono::high_resolution_clock::time_point testMemcpyStart = std::chrono::high_resolution_clock::now();
	#include <time.h>
	//clock_t begin = clock();
        gettimeofday(&startTime, NULL);
        memcpy(dstptr,rawData,size);
        gettimeofday(&endTime, NULL);
	 printf("time taken :[%lld] microsec\n",(((endTime.tv_sec * 1000LL + endTime.tv_usec)- (startTime.tv_sec * 1000LL + startTime.tv_usec))));
	/*clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("[%f]sec\n", time_spent);*/
        /*measure the memcpy time end**/
    //    std::chrono::high_resolution_clock::time_point testMemcpyEnd = std::chrono::high_resolution_clock::now();
      //  LOGI("test memcpy Time:[%lf]msec",std::chrono::duration<double, std::milli>(testMemcpyEnd-testMemcpyStart).count());
        free(dstptr);
        i++;
    }
}

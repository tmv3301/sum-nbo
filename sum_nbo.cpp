#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
	int i;
	uint32_t sum=0;
	for(i=1;i<argc;i++){
		FILE *file=fopen(argv[i],"rb");
		if(!file){
			perror("FILE OPEN ERROR");
			return 1;
		}
		uint32_t num;
		if(fread(&num,sizeof(uint32_t),1,file)!=1){
			fprintf(stderr,"ERROR(READING):%s\n",argv[i]);
			fclose(file);
			return 1;
		}
		fclose(file);
		num=ntohl(num);
		printf("%u(0x%x) ",num,num);
		if(i<argc-1){
			printf("+ ");
		}
		sum+=num;
	}
	printf("= %u(0x%x)\n",sum,sum);
	return 0;
}

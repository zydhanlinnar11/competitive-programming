#include <stdio.h>
#include <string.h>
int main(){
	int i,L;
	while(scanf("%d",&L)){
		if(L==0){
			return 0;
		}
		char ps[3]="+x";
		printf("%s\n",ps);
		for(i=1; i<L; i++){
			char c[8];
			scanf("%s",c);
			if(strcmp(c,"No")==0)
				continue;
			else {
				if(strcmp(c,"+y")==0){
					if(strcmp(ps,"+x")==0 || strcmp(ps,"-x")==0)
						strcpy(ps,"bebek");
					else if(strcmp(ps,"+y")==0 || strcmp(ps,"-y")==0)
						strcpy(ps,"-x");
				}
				else if(strcmp(c,"-y")==0){
					if(strcmp(ps,"+x")==0 || strcmp(ps,"-x")==0)
						strcpy(ps,"-y");
					else if(strcmp(ps,"+y")==0 || strcmp(ps,"-y")==0)
						strcpy(ps,"+x");
				}
				else if(strcmp(c,"+z")==0){
					if(strcmp(ps,"+x")==0 || strcmp(ps,"-x")==0)
						strcpy(ps,"+z");
					else if(strcmp(ps,"+z")==0 || strcmp(ps,"-z")==0)
						strcpy(ps,"-x");
				}
				else if(strcmp(c,"-z")==0){
					if(strcmp(ps,"+x")==0 || strcmp(ps,"-x")==0)
						strcpy(ps,"-z");
					else if(strcmp(ps,"+z")==0 || strcmp(ps,"-z")==0)
						strcpy(ps,"+x");
				}
			}
			// printf("%s\n",ps);
		}
		printf("%s\n",ps);
	}
	return 0;
}
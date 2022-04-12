#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

struct student {
	long long int number; //for 202010205557
	char *name;
	float vizeNotu;
	float finalNotu;
	float donemNotu;
	struct student * next;
};
 typedef struct student node;
 node * head, *newNode;
 
void creatList(void);
void deleteNode(void);
void listingStudent(void);
void update(void);
void average(void);
void successful(void);
void digerIslemler(void);
void exchange(void);
void listLess(void);
void updateAhmet(void);
int alarm(void);

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Turkish");
	int select;
	start :
	system("cls");
	printf("=> Ana menü: \n 1-Yeni kayýt oluþturma\n 2-Kayýt silme\n 3-Kayýt listeleme\n 4-Kayýt güncelleme\n 5-Sýnýf ortalamasý\n 6-En baþarýlý öðrenci\n 7-Diðer iþlemler\n 8-Çýkýþ yap\n=> : ");
	scanf("%d",&select);
	switch(select){
		case 1: creatList(); break;
		case 2: deleteNode(); break;
		case 3: listingStudent(); break;
		case 4: update(); break;
		case 5: average(); break;
		case 6: successful(); break;
		case 7: digerIslemler(); break;
		case 8: exit(0);
		default : printf(" Hata giriþ yaptýnýnýz !!! \n"); 
	} if(alarm()==1){goto start;} 
	return 0;
}
void digerIslemler(){
	int select;	
	system("cls");
	printf("=> Diðer iþlemler\n");
	printf("  1-Ýlk öðrenci ile son öðrenci ile deðiþtirme\n  2-Baþarý notu 60'ýn altýndakileri silme\n  3-Ahmet ismi AHMET yapma\n=> : ");
	scanf("%d",&select);
	switch(select){
		case 1: exchange(); break;
		case 2: listLess(); break;
		case 3: updateAhmet();break;
		default : printf(" Hata giriþ yaptýnýz !!!\n"); break;
	}
}
int alarm(){
	int select;
 	start :
 	printf("=> 1-Ana menü\n   2-Ýþlemi bitir ve Çýk\n=> : ");scanf("%d",&select);
 	switch(select){
		case 1:	system("cls"); return 1;
		case 2:  return 0; 
		default : system("cls"); printf(" Hata giriþ yaptýnýnýz !!! \n");  goto start;
	}	
}
void creatList(){
 	int size, i;
 	node *add, *p;
 	printf("Kaç tane kayýt olacak : ");
 	scanf("%d",&size);
 	for(i=0;i<size;i++){
 		add=(node *)malloc(sizeof(node));
 		add->next=NULL;
 		system("cls");
	 	printf("=> Yeni kayýt oluþturma\n");
 		printf(" Öðrenci numara : ");scanf("%lld",&add->number);		
 		add->name=(char *)malloc(50*sizeof(char));
 		printf(" Öðrenci Adý : ");scanf("%s",add->name);
 		printf(" Vize notu : ");scanf("%f",&add->vizeNotu);
 		printf(" Final notu : ");scanf("%f",&add->finalNotu);
 		add->donemNotu=(add->vizeNotu*0.4)+(add->finalNotu*0.6);
 		
 		if(head==NULL){
		 	head=add;
 		}
	 	else {
		 	add->next=head;head=add;
	 	}
		
		add=add->next;
	 }	
}

void deleteNode(void){
	long long int stdNo;
	node *p, *q;
	x:
	printf("=> Kayýt silme\n");
	printf("  Silmek istediðiniz öðrenci no gir : ");scanf("%lld",&stdNo);
	p=head;
	
	if(p->number==stdNo){
	   	
	   	 int n;
		 printf(" Silinsýn mý? Evet-[1] Hayýr-[0]\n");scanf("%d",&n);
		 if(n==1){  head=p->next;  free(p); printf(" Kayýt silindi!!!\n"); } 
 		 else goto x;		 
		 }
	else{ 
		while(p->next!=NULL){
			if(p->number==stdNo) break;
		   	else {
		   		q=p;
 		        p=p->next;	
			   }
	 		} 
	    if(p->number==stdNo){			  
			 int n;
			 printf(" Silinsýn mý? Evet-[1] Hayýr-[0]\n ");scanf("%d",&n);
 			 if(n==1){
 			   q->next=p->next;
			   free(p); 
			   printf(" Kayýt silindi!!!\n"); 
			   } 
 			 else goto x;
	 	}
	 	
	    else  if(p->next==NULL){
			 printf(" [%lld] nolu öðrenci bulunamadý!!! \n",stdNo);
		}
	}	
}
int searchStudent1(node *temp){	
 	int sayac=0;
 	long long int searchNum;
 	printf(" Aramak istediðiniz öðrenci no giriniz : "); scanf("%lld",&searchNum);
 	while(temp!=NULL){
 	           		if(searchNum==temp->number){					
 					printf(" ---------------------\n");
 					printf(" Öðrenci numara : %lld\n",temp->number);
     				printf(" Öðrenci Adý : %s\n",temp->name);
     				printf(" Vize Notu : %.2f\n",temp->vizeNotu);
     				printf(" Final Notu : %.2f\n",temp->finalNotu);
     				printf(" Dönem Notu : %.2f\n",temp->donemNotu);
     				printf(" ---------------------\n");	sayac++;}   
 					temp=temp->next; }
	 if(sayac==0){ return 0;} else return 1;				
}
int searchStudent2(node *temp){
 	int sayac=0;
  	char *searchName=(char *)malloc(30*sizeof(char));
	 printf(" Aramak istediðiniz isimi giriniz : ");	scanf("%s",searchName);	
     printf("=> Öðrenci listesi :\n =====================\n");
 	while(temp!=NULL){
 	           		if(strstr(temp->name,searchName)!=NULL){					
 					printf(" ---------------------\n");
 					printf(" Öðrenci numara : %lld\n",temp->number);
     				printf(" Öðrenci Adý : %s\n",temp->name);
     				printf(" Vize Notu : %.2f\n",temp->vizeNotu);
     				printf(" Final Notu : %.2f\n",temp->finalNotu);
     				printf(" Dönem Notu : %.2f\n",temp->donemNotu);
     				printf(" ---------------------\n");	sayac++;}   
 					temp=temp->next;}
 	 printf(" =====================\n");
	 printf(" Öðrenci sayýsý : %d\n",sayac);
	 printf(" =====================\n");
	 if(sayac==0){ return 0;} else return 1;
}
int searchStudent3(node *temp){
	int sayac=0;	
     printf("=> Öðrenci listesi :\n =====================\n");
 	while(temp!=NULL){
 	           		if(temp->donemNotu>=60){					
 					printf(" ---------------------\n");
 					printf(" Öðrenci numara : %lld\n",temp->number);
     				printf(" Öðrenci Adý : %s\n",temp->name);
     				printf(" Vize Notu : %.2f\n",temp->vizeNotu);
     				printf(" Final Notu : %.2f\n",temp->finalNotu);
     				printf(" Dönem Notu : %.2f\n",temp->donemNotu);
     				printf(" ---------------------\n");	sayac++;}   
 					temp=temp->next;}
 	 printf(" =====================\n");
     printf(" Öðrenci sayýsý : %d\n",sayac);
     printf(" =====================\n");
     if(sayac==0){ return 0;} else return 1;
}
int searchStudent4(node *temp){
	int sayac=0;	
     printf("=> Öðrenci listesi :\n =====================\n");
 	while(temp!=NULL){
 	           							
 					printf(" ---------------------\n");
 					printf(" Öðrenci numara : %lld\n",temp->number);
     				printf(" Öðrenci Adý : %s\n",temp->name);
     				printf(" Vize Notu : %.2f\n",temp->vizeNotu);
     				printf(" Final Notu : %.2f\n",temp->finalNotu);
     				printf(" Dönem Notu : %.2f\n",temp->donemNotu);
     				printf(" ---------------------\n");	sayac++;   
 					temp=temp->next;}
 	 printf(" =====================\n");
     printf(" Öðrenci sayýsý : %d\n",sayac);
     printf(" =====================\n");
     if(sayac==0){ return 0;} else return 1;
}
void listingStudent(){
	int search;
	node *temp;
	temp=head;
	system("cls");
	printf("=> Kayýt listeleme\n  1-Numaraya göre arama\n  2-Ýsme göre arama\n  3-Baþarý notu 60 ve üzeri\n  4-Tüm öðrencileri listele\n=> : ");scanf("%d",&search);
	switch(search){
		case 1:	if(searchStudent1(temp)==0){printf(" Aranan öðrenci no bulunamadý!!!\n");}break;
	 	case 2:	if(searchStudent2(temp)==0){printf(" Aranan öðrenci ismi bulunamadý!!!\n");}break;	 
		case 3: if(searchStudent3(temp)==0){printf(" Baþi notu 60 ve üzeri öðrenci bulunamadý!!!\n");}break;
		case 4: if(searchStudent4(temp)==0){printf(" Öðrenci bulunamadý!!!\n");}break;
		default : printf(" Hata giriþ yaptýnýnz!!!\n"); break;
	}
 }
void average(void){
	float ortalama;
	int sayac=0;
	node * ort=head;
	if(ort==NULL) {printf(" Kayýt listesi boþ!!! \n");}
	while(ort!=NULL){
		ortalama+=ort->donemNotu;
		ort=ort->next;
		sayac++;
	}
	if(sayac!=0) printf(" Sýnýf Not ortalamasý : %.2f\n",ortalama/sayac);	
}
void successful(void){
	node *basari=head, *basarisiz=head;
	if(basarisiz==NULL) {printf(" Kayýt listesi boþ!!! \n");}
	while(basarisiz!=NULL){
		if(basari->donemNotu<basarisiz->donemNotu){
			basari=basarisiz;
		}
		basarisiz=basarisiz->next;
	}
		printf(" ---------------------\n");
 		printf(" Öðrenci numara : %lld\n",basari->number);
   		printf(" Öðrenci Adý : %s\n",basari->name);
   		printf(" Vize Notu : %.2f\n",basari->vizeNotu);
   		printf(" Final Notu : %.2f\n",basari->finalNotu);
   		printf(" Dönem Notu : %.2f\n",basari->donemNotu);
     	printf(" ---------------------\n");
}
int searchStudent5(node *temp){	
 	int sayac=0;
 	long long int searchNum;
 	printf(" Güncellemek istediðiniz öðrenci no giriniz : "); scanf("%lld",&searchNum);
 	while(temp!=NULL){
 	           		if(searchNum==temp->number){					
 					printf(" ---------------------\n");
 					printf(" Öðrenci numara : %lld\n",temp->number);
     				printf(" Öðrenci Adý : %s\n",temp->name);
     				printf(" Vize Notu : %.2f\n",temp->vizeNotu);
     				printf(" Final Notu : %.2f\n",temp->finalNotu);
     				printf(" Dönem Notu : %.2f\n",temp->donemNotu);
     				printf(" ---------------------\n");	
 				    printf(" Öðrencinin yeni adý : ");scanf("%s",temp->name);
 	                printf(" Öðrencinin yeni vize notu : ");scanf("%f",&temp->vizeNotu);
 	                printf(" Öðrencinin yeni final notu : ");scanf("%f",&temp->finalNotu);
 	                temp->donemNotu=(temp->vizeNotu*0.4)+(temp->finalNotu*0.6);
 	                printf(" Kayýt güncellendi !!!\n");sayac++;}   
 					temp=temp->next; }			
	 if(sayac==0){ return 0;} else return 1;				
}
void update(){
	node *temp;
	temp=head;
	if(searchStudent5(temp)==0){printf(" Girilen öðrenci no bulunamadý!!!\n");}
}
void exchange(){
	node *ilkKayit, *sonKayit, *temp;
	ilkKayit=head;
	sonKayit=head;
	while(sonKayit->next!=NULL){
		temp=sonKayit;
		sonKayit=sonKayit->next;
	}		
 		sonKayit->next=ilkKayit->next;
	 	temp->next=ilkKayit;
 		ilkKayit->next=NULL;
 		head=sonKayit;	
	printf(" Kayýtlar deðiþtirildi.\n");
}
void listLess(){
	int sayac=0;
	node *sonKayit=head, *temp;
	while (sonKayit != NULL && sonKayit->donemNotu < 60) {
        head = sonKayit->next; 
        free(sonKayit); 
        sonKayit = head; 
        sayac++;
    }		
	while(sonKayit!=NULL){
 		while (sonKayit != NULL && sonKayit->donemNotu >= 60) {
             temp = sonKayit;
             sonKayit = sonKayit->next;
         	}
         	if(sonKayit==NULL) break;
         	
         	temp->next=sonKayit->next;
         	free(sonKayit);
         	sonKayit=temp->next;
         	sayac++;
		} 	
 	if(sayac==0){
 		printf(" Baþarý notu 60'ýn altýnda olan öðrenci bulunamadý\n");
	 }
 	else  printf(" Iþlem bitti\n");	
}
void updateAhmet(){
	node *ahmet=head;
		while(ahmet!=NULL){
		 	if(strcmp(ahmet->name,"Ahmet")==0){
	 			char *upper=ahmet->name;
			 	int i=0;
			 	while(upper[i]!='\0'){
					upper[i]=toupper(upper[i]);
				 i++;
			 	}break;
	 		}
	 	ahmet=ahmet->next;
	 	}
	 	if(ahmet==NULL) {printf(" Ahmet ismi bulunamadý!!!\n");}
	 	else printf(" Iþlem bitti\n");
}


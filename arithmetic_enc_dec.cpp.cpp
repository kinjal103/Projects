#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fcntl.h>

#define MAX 256
#define LIMIT 2047

struct symbol{
    int count;
    int cum_count;
    char symbie;
    symbol(){
        count = 0;
        cum_count = 0;
        symbie = 0;
    }
}sym[MAX];

int l, u, sym_cnt=0, total, total_bits;
char encode[LIMIT];

int exist(char ch){
    int i=0;
    for(i=0;i<sym_cnt;i++){
        if(sym[i].symbie==ch){
            return 0;
        }
    }
    return 1;
}

int inc_freq(char ch){
    for(int i=0;i<sym_cnt;i++){
        if(sym[i].symbie==ch){
            sym[i].count++;
            return 1;
        }
    }
    return 0;
}

void sort(){
    int i=0, j=0, min;
    struct symbol temp;
    for(i=0;i<(sym_cnt-1);i++){
        min=i;
        for(j=i+1;j<sym_cnt;j++){
            if(sym[j].symbie<sym[min].symbie){
                min=j;
            }
        }
        if(min!=i){
            temp=sym[i];
            sym[i]=sym[min];
            sym[min]=temp;
        }
    }
}

void initialize(){
    for(int i=1;i<sym_cnt;i++){
        for(int j=i;j>=0;j--){
            sym[i].cum_count+=sym[j].count;
        }
    }
}

int maximum(int a){
    int temp = 1;
	int i=1;
	while((temp-1)<a)
	{
		temp*=2;
		i++;
	}
	total_bits = i-1;
	return (temp-1);
}

int index(char ch){
    for(int i=0;i<sym_cnt;i++)
	{
		if(sym[i].symbie==ch)
			return i;
	}
}

int shift(int a, int lsb){
    a<<=1;
    if(lsb==0){
        a&=(MAX-1);
    }
    else{
        a&=MAX;
        a|=1;
    }
    return a;
}

int msb(int a){
    if((a)&(MAX+1)/2){
        a&=(((MAX+1)/2)-1);
    }
    else{
        a|=((MAX+1)/2);
    }
    return a;
}

int main(){
    int max, cur_index, cur_cum_count, prev_cum_count, temp, e1, e2, scale3=0;
    FILE *fin;
    char ch;
    fin = fopen("input","r");
    while((ch = getc(fin) !=EOF)){
        if(exist(ch)){
            sym[sym_cnt].symbie=ch;
            sym[sym_cnt].count=1;
            sym_cnt++;
        }
        else{
            inc_freq(ch);
        }
    }
    sort();
    initialize();
    total = sym[sym_cnt-1].cum_count;
    l=0;
    u=maximum(total*4);
    max=u;
    
    fclose(fin);
    fin=fopen("input","r");
    while((ch=getc(fin)!=EOF)){
        cur_index=index(ch);
        if(cur_index==0){
            cur_cum_count=sym[0].cum_count;
            prev_cum_count=0;
        }
        else{
            cur_cum_count=sym[cur_index].cum_count;
            prev_cum_count=sym[cur_index-1].cum_count;
        }
        
        temp = l + (((u-l+1)*prev_cum_count)/total);
        u = l + (((u-l+1)*cur_cum_count)/total) - 1;
        l=temp;
        
        while((l<max/2)&&(u<(max/2)) || ((l>max/2)&&(u>max/2)) || ((l>max/4)&&(u<3*max/4))){
            if((l<max/2) && (u<max/2)){
                //cout<<"E1";
                strcat(encode,"0");
                while(scale3!=0){
                    strcat(encode,"1");
                    scale3--;
                }
                l = shift(l,0);
                u = shift(u,1);
            }
            else if((l>max/2) && (u>max/2)){
                //cout<<"E2";
                strcat(encode,"1");
                while(scale3!=0){
                    strcat(encode,"0");
                    scale3--;
                }
                l = shift(l,0);
                u = shift(u,1);
            }
            else if((l>max/4) && (u<3*max/4)){
                scale3++;
                //cout<<"E3";
                l = shift(l,0);
                u = shift(u,1);
                l = msb(l);
                u = msb(u);
            }
        }
    }
    fclose(fin);
    return 1;
}

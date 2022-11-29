int main(int argc, const char * argv[]) {
  FILE *fp;
  int val;
  fp=openfil("test.txt");
  
  printf("Ange 1 för skrivning, annat för läsning: ");
  scanf("%i",&val);
  if(val==1)
    skriv(fp);
  else
    las(fp);
  fclose(fp);
  return 0;
}

FILE *openfil(char namn[]){
  FILE *fp;
  if ((fp = fopen(namn, "r+")) == NULL)// om den finns
    if ((fp = fopen(namn, "w+")) == NULL){
      printf("fel\n");
      return NULL; // vid fel, OBS! vi borde ta hand om det. Fråga vad jag menar!
      // exit(1);
  }
  return fp; //Om allt går bra returnerar vi fp
}

void skriv(FILE *fp){
  char men[50],tkn;
  printf("Ange en mening:"); gets(men);
  fputs(men,fp); fputc('\n',fp);
  printf("Ange en till mening:"); gets(men);
  fputs(men,fp); fputc('\n',fp);
  printf("Ange ett tecken:"); scanf("%c",&tkn);
  fputc(tkn,fp); fputc('\n',fp);
}

void las(FILE *fp){
  char tkn;
  tkn=fgetc(fp);
  while(!feof(fp)){
    printf("%c",tkn);
    tkn=fgetc(fp);
   }
}

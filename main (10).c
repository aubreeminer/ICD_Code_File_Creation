#define INPUT_BUFFER 1024
#define MAX_FNAME 32
#define MAX_LNAME 32
#define MAX_STREET_NAME 64
#define MAX_CITY_NAME 64
#define MAX_STATE 2
#define MAX_ICD_LEN 10
#define MAX_ICD_ENT 4
#define MAX_TYPE_LEN 9
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pmtr{
  unsigned int c; 
  char* fileName;

} parm;

typedef struct ICD{
  char* code;
  size_t code_Len;
  unsigned int date;
 }ICD;

typedef struct phoneInfo{
unsigned int phoneNum;
char* type;
}phoneInfo;

enum phoneType{
null = 0,
Home,
Work,
Cell
 } choice;


char* state;
enum States{
    NONE=0,
    AK,
    AL,
    AR,
    AZ,
    CA,
    CO,
    CT,
    DE,
    DC,
    FL,
    GA,
    HI,
    ID,
    IL,
    IN,
    IA, 
    KS,
    KY,
    LA,
    ME,
    MD,
    MA,
    MI,
    MN,
    MS,
    MO,
    MT,
    NE,
    NH,
    NY,
    NC,
    ND,
    NM,
    NV,
    NJ,
    OH,
    OK,
    OR,
    PA,
    RI,
    SC,
    SD,
    TN,
    TX,
    UT,
    VT,
    VA,
    WA,
    WV,
    WI,
    WY

  };

bool validState = true;
enum States stateEnum;
void inputCleaner(char *buff) 
{
  int target = strlen(buff) - 1; 
  if (buff[target] == '\n')
    buff[target] = '\0';
}
void isStateValid(char stateChar1, char stateChar2){
  validState = true;
  switch(stateChar1){
  case 'A':
  switch(stateChar2){
    case 'K':
    stateEnum = AK;
    break;
  case 'L':
    stateEnum = AL;
    break;
  case 'R':
    stateEnum = AR;
    break;
    case 'Z':
      stateEnum = AZ;
    break;
  default:
    stateEnum = NONE;
  validState = false;
}
break;

  case 'C':
  switch(stateChar2){
    case 'A':
      stateEnum = CA;
      break;
    case 'O':
      stateEnum = CO;
      break;
    case 'T':
      stateEnum= CT;
      break;
  default:
    stateEnum = NONE;
  validState = false;
 
}
break;

  case 'D':
  switch(stateChar2){
    case 'E':
      stateEnum = DE;
      break;
    case 'C':
      stateEnum = DC;
      break;
     default:
       stateEnum = NONE;
  validState = false;

  }
  break;
case 'F':
  switch(stateChar2){
    case 'L':
      stateEnum = DE;
      break;
     default:
       stateEnum = NONE;
  validState = false;

  }
break;

  case 'G':
  switch(stateChar2){
    case 'A':
      stateEnum = DE;
      break;
    default:
      stateEnum = NONE;
  validState = false;

  }
break;
  
case 'H':
  switch(stateChar2){
    case 'I':
      stateEnum = DE;
      break;
     default:
       stateEnum = NONE;
  validState = false;

  }
break;
  
case 'I':
  switch(stateChar2){
    case 'L':
      stateEnum = IL;
      break;
    case 'N':
      stateEnum = IN;
      break;
    case 'A':
      stateEnum = IA;
      break;
     default:
       stateEnum = NONE;
  validState = false;
  
  }
break;
  
case 'K':
  switch(stateChar2){
    case 'L':
      stateEnum = IL;
      break;
    case 'N':
      stateEnum = IN;
      break;
    case 'A':
      stateEnum = IA;
      break;
     default:
       stateEnum = NONE;
  validState = false;

  }
break;

case 'L':
  switch(stateChar2){
    case 'A':
      stateEnum = LA;
      break;
     default:
       stateEnum = NONE;
  validState = false;

  }
break;
  
case 'M':
  switch(stateChar2){
    case 'A':
      stateEnum = MA;
      break;
    case 'I':
      stateEnum = MI;
      break;
    case 'N':
      stateEnum = MN;
      break;
    case 'O':
      stateEnum = MO;
      break;
    case 'T' :
      stateEnum = MT;
      break;
    case 'E':
      stateEnum = ME;
      break;
    case 'S' :
      stateEnum = MS;
      break;
     
     default:
       stateEnum = NONE;
  validState = false;

  }
break;
  
case 'N':
  switch(stateChar2){
    case 'E':
      stateEnum = NE;
      break;
    case 'V':
      stateEnum = NH;
      break;
    case 'H':
      stateEnum = NH;
      break;
    case 'J':
      stateEnum = NJ;
      break;
    case 'M' :
      stateEnum = NM;
      break;
    case 'Y':
      stateEnum = NY;
      break;
    case 'C' :
      stateEnum = NC;
      break;
    case 'D' :
      stateEnum = ND;
      break;
     default:
       stateEnum = NONE;
  validState = false;
 

  }
break;
  
case 'O':
  switch(stateChar2){
    case 'H':
      stateEnum = OH;
      break;
    case 'K':
      stateEnum = OK;
      break;
    case 'R':
      stateEnum = OR;
      break;
      default:
        stateEnum = NONE;
  validState = false;
  }
break;
  
case 'P':
  switch(stateChar2){
    case 'A':
      stateEnum = PA;
      break;
      default:
        stateEnum = NONE;
  validState = false;
  }
  break;
  
  case 'R':
    switch(stateChar2){
      case 'I':
        stateEnum = RI;
      break;
      default:
        stateEnum = NONE;
  validState = false;

  }
break;
  
  case 'S':
    switch(stateChar2){
      case 'C':
        stateEnum = SC;
      break;
      case 'D':
        stateEnum= SD;
      default:
        stateEnum = NONE;
  validState = false;
    }
break;
  
case 'T':
  switch(stateChar2){
    case 'N':
        stateEnum = TN;
      break;
    case 'X':
        stateEnum= TX;
      break;
      default:
        stateEnum = NONE;
  validState = false;
    }
  break;
  
case 'U':
    switch(stateChar2){
      case 'T':
        stateEnum = UT;
      break;
      default:
        stateEnum = NONE;
  validState = false;

      }
break;
  
case 'V':
  switch(stateChar2){
    case 'T':
        stateEnum = VT;
      break;
    case 'A':
        stateEnum= VA;
      break;
      default:
        stateEnum = NONE;
  validState = false;
 
    }
break;
  
case 'W':
  switch(stateChar2){
    case 'I':
        stateEnum = WI;
      break;
    case 'A':
        stateEnum= WA;
      break;
    case 'V':
        stateEnum = WV;
      break;
    case 'Y':
        stateEnum = WY;
      break;
      default:
        stateEnum = NONE;
  validState = false;
 
    }
 
  default: 
    validState =false;
 break;
  
  }
};
  
void clearBuffer(char* buffer)
{
    memset(buffer, '\0', INPUT_BUFFER);
}

int GetValidatedString(size_t stringMax, char*buffer)
{
    int retVal = 1;
    fgets(buffer, INPUT_BUFFER, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    if ((strlen(buffer) <= 0) || (strlen( buffer) > stringMax))
    {
        printf("The input length must be between 0 and %zu\n", stringMax);
        clearBuffer(buffer);
        retVal = 0;
    }

    return retVal;
}
// size_t itoa(unsigned int num, char* buffer) {
//   size_t idx = strlen(buffer);
//   unsigned int mod = 1000000000;
//   while(num>0){
//     unsigned int digit = num/mod;
//     num %= mod;
//     mod/=10;
//     digit +=32;
//     buffer[idx+1] = (char) digit;
//     buffer[idx+2]='\0';
//     }
//   return strlen(buffer);
//   }
void showHelp(){
  printf("Help Menu\nAccepted Parameters\n");
  printf("\t-c n : \n\tSpecifies an input of n ICD code inputs\n");
  printf("\t-r Doe_John_#.icd : \n\tLoads the given EMR file of John Doe, with the corresponding record number #\n");
  printf("NOTE: -c & -r are logically exclusive commands, and as such are invalid when paired\n");
  printf("\t-h : \n\tHelp menu\n");
  printf("\n\n");
}
int parse(int argc, char* argv[], parm *preset){
 char control = argv[1][1]; // switch control variable, grabs letter of param
  preset->c = MAX_ICD_ENT;
  preset->fileName[INPUT_BUFFER];

  while (true) 
  { 
    switch (control) 
    {
      case 'c': // count update
      {
        preset->c = atoi(argv[2]); 
        if(preset->c < 0)
        {
          printf("Invalid Data: -c must be followed by a positive number.\n");
          return 0;
        }
        return 1;
      }
      case 'r': // reload
      { 
        strcpy(preset->fileName, argv[2]);
        return 2; 
      }
      case 'h': //help
      default: 
      {
        showHelp();
        return 0; 
      }
    }
  }
} 


int main(int argc, char* argv[]) {
 
  int zip;
  int FourDig;
 //unsigned int* icdDates = (unsigned int *) calloc(MAX_ICD_ENT, sizeof(int));
 //  char** icdCode = (char**) calloc(MAX_ICD_ENT, sizeof(char*));
  int nameSize;
    int icdEntries = MAX_ICD_ENT;
  unsigned int phoneNum;
  phoneInfo* P =NULL;
   ICD* I= NULL;
  int fileNum = 0;
  bool skip = false;
  bool prompt = true; 
  FILE *icdPtr = NULL;
  FILE *idxPtr = NULL;
  P = (struct phoneInfo*)malloc(sizeof(struct phoneInfo));
  I = (struct ICD*)malloc(sizeof(struct ICD));
 char buffer[INPUT_BUFFER];
  char*fname = NULL;
  char*lname = NULL;
  char* sname = NULL;
  char* city = NULL;
  char* state = NULL;
 int phoneN;
  int result = 0;

  int r;
  char clear;
  int i;
  bool load = false;
  parm* preset = NULL;
  int c = MAX_ICD_ENT;
  preset = (parm*) calloc (1, sizeof(parm));
  preset->fileName[INPUT_BUFFER];
  preset ->c = MAX_ICD_ENT;


  switch(argc){
    case 3:{
    r = parse(argc, argv,preset);
      prompt = false;
        if (r == 1){
          load = false;
        }
        if (r == 2){
          load = true;
        }
        if (r == 0){
          return 1;
        }
      }
    
    case 1:{
      idxPtr = fopen("ICD.idx", "ra");
      if(idxPtr == NULL){
         fileNum = 0;
        idxPtr = fopen("ICD.idx", "wra");
        fprintf(idxPtr, "%d", fileNum);
        fclose(idxPtr);
      }
      else{
       fscanf(idxPtr, "%d", &fileNum);
        fclose(idxPtr);
      }
      break; 
      }
    
    case 0:{
      printf("NO\n");
      return 1;
    }
    default:{
      showHelp();
      printf("Command invalid! Stopping program.\n");
      return 0;
    } 
  }
  

  if(fileNum != 0 &&prompt){
     
        char input;
        printf("%s", "Would you like to load data from a previous entry?\n\tY/N: (must be capitalized)");
        scanf("%c", &input);
        while((getchar())!= '\n'); 
        if(input == 'Y')
            load = true;
    }
	
	if(load)
	{
    if(prompt){
    
        printf("%s", "  asking for data  \n");
        
        printf("%s", "\n Enter first and last name and record number:\n");
       
        int result;
        printf("%s","First Name: ");
        result = GetValidatedString(MAX_FNAME, buffer);
        while(true)
        {
        	if(result == 1 )
        	{
        	   fname = (char *) calloc (MAX_FNAME + 1, sizeof(char));
        	   strcpy(fname,buffer);
        	   break;
        	}   
        	else
        		printf("Invalid first name, please retry");
        }
 printf("%s", "Last Name: ");
      result = GetValidatedString(MAX_LNAME, buffer);
      while (true) 
      {
        if (result == 1) 
        {
          lname = (char *)calloc(MAX_LNAME + 1, sizeof(char));
          strcpy(lname, buffer);
          break;
          }
        else
          printf("Invalid last name, please retry");
      }
   int inputNum;
        printf("%s" ,"Record Number: ");
        scanf("%d", &inputNum);
        
        memset(buffer, '\0', INPUT_BUFFER); 
        sprintf(buffer, "%s_%s_%d.icd", lname, fname, inputNum); 
        free(fname);
        free(lname);
      }
   
    
    
        icdPtr = fopen(buffer, "r");
        if(icdPtr == NULL)
        {
            printf("%s", "Invalid data, ending program");
            return 0; 
        }
        else
        { 
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, MAX_FNAME + 1, icdPtr);
                inputCleaner(buffer);
                fname = (char *) calloc (strlen(buffer) + 1, sizeof(char));
                strcpy(fname, buffer);
                
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, MAX_LNAME + 1, icdPtr);
                inputCleaner(buffer);
                lname = (char *) calloc (strlen(buffer) + 1, sizeof(char));   
                strcpy(lname, buffer);
                
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, MAX_STREET_NAME + 1, icdPtr);
                inputCleaner(buffer);
                sname = (char *) calloc (strlen(buffer) + 1, sizeof(char));   
                strcpy(sname, buffer);
                
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, MAX_CITY_NAME + 1, icdPtr);
                inputCleaner(buffer);
                city = (char *) calloc (strlen(buffer) + 1, sizeof(char));
                strcpy(city, buffer);
                
                
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, INPUT_BUFFER + 1, icdPtr); 
                inputCleaner(buffer);
                state = (char *) calloc (strlen(buffer) + 1, sizeof(char));   
                strcpy(state, buffer);  
                
               
              
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, 6, icdPtr);
                inputCleaner(buffer);
                zip = atoi(buffer);
                fgetc(icdPtr);
                
                P = (phoneInfo*) calloc (1,sizeof(phoneInfo));
        
                
                memset(buffer, '\0' , INPUT_BUFFER);
                fgets(buffer, 11, icdPtr);
                inputCleaner(buffer);
               P->phoneNum = atoi(buffer);
                fgetc(icdPtr);
                
                // memset(buffer, '\0' , INPUT_BUFFER);
                // fgets(buffer, INPUT_BUFFER + 1, icdPtr);
                // inputCleaner(buffer);
                // P->type = (char*) calloc(strlen(buffer) + 1, sizeof(char));
                // strcpy(P->type, buffer);
            
                // I = (ICD*) calloc (preset->c, sizeof(ICD));
                // for(i = 0; i < preset->c; i++)
                // {
                //     fscanf(icdPtr, "%u", &I[i].date);
                //     fgetc(icdPtr);
                    
                //     memset(buffer, '\0' , INPUT_BUFFER);
                //     fgets(buffer, MAX_ICD_LEN + 1, icdPtr);
                //     I[i].code = (char*) calloc(strlen(buffer) + 1, sizeof(char));
                //     strcpy(I[i].code, buffer);
                //     fgetc(icdPtr);
                
          int position;
      fgetpos(icdPtr, &position);
      int lines = 0;
      char x;
      do
      {
      	x = fgetc(icdPtr);
      	if(x == '\n') 
      		lines++;
      } while (x != EOF);
      
      icdEntries = lines/2;
      I = (ICD*) calloc (icdEntries, sizeof(ICD));
      fsetpos(icdPtr, &position);
      for (i = 0; i < icdEntries; i++)  
      {
        fscanf(icdPtr, "%u", &I[i].date);
        fgetc(icdPtr);

        memset(buffer, '\0', INPUT_BUFFER);
        fgets(buffer, MAX_ICD_LEN + 1, icdPtr);
        I[i].code = (char *)calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(I[i].code, buffer);
        fgetc(icdPtr);
          }
            
            fclose(icdPtr);
    	}
    }
  



else if(!skip){
printf("Enter User data\n");
 while(true){
    printf("Please give your first name: \n");
    result = GetValidatedString(MAX_FNAME, buffer);
  if(result ==1){
    fname =(char*)malloc((strlen(buffer)+1)*sizeof(char));
  strcpy(fname,buffer);
  break;
    }
  else
			printf("Invalid first name, please retry");
    }
 

  
while(true){
    printf("Please give your last name: \n");
    result = GetValidatedString(MAX_LNAME, buffer);
    
  if(result ==1){
    lname =(char*)malloc((strlen(buffer)+1)*sizeof(char));
  strcpy(lname,buffer);
  break;
    }
  else
    printf("Invalid last name, please retry");
  }

 
 while(true){
    printf("Please enter street name with house number :\n");
    result = GetValidatedString(MAX_STREET_NAME, buffer);
    if(result ==1){
    sname =(char*)malloc((strlen(buffer)+1)*sizeof(char));
  strcpy(sname,buffer);
      
 break;
   }
   else
   printf("Invalid street address, please retry");
   
 }


  while(true){
    printf("Please enter city name :\n");
    result = GetValidatedString(MAX_CITY_NAME, buffer);
    
  if(result ==1){
    city =(char*)malloc((strlen(buffer)+1)*sizeof(char));
  strcpy(city,buffer);
    break;
    }
    else
  printf("Invalid city try again");
    }
  
while(true){
  printf("\nPlease enter abbreviated state: ");
  memset(buffer, '\0', INPUT_BUFFER);
  scanf("%s",buffer);
  isStateValid(buffer[0],buffer[1]);
  if(strlen(buffer) == 2 && validState){
    state = (char*)calloc(MAX_STATE + 1, sizeof(char));
    strcpy(state, buffer);
    //printf("%s",state);
    break;
  }
  else{
    printf("\nInvalid entry '%s', please retry",buffer);
    }
free(state);
  }
  

 printf("Enter zipcode:\n");
 scanf("%i", &zip );
 printf("Enter 4 digit zipcode:\n");
 scanf("%i", &FourDig);
 
while(true){
			printf("Please enter your phone number (no space):\n ");  
			scanf("%d", &phoneN);
			if(phoneN != 0)
				break;
			else
				printf("Invalid, try again\n");		
		}
	 
	for(i=0;i < 1;i++) 
		{
			while(true) 
			{
			    int phoneChoice = 0;
				printf("\nPlease choose the phone type\nHome: 1\nWork: 2\nCell: 3\nType: ");
				scanf("%u", &phoneChoice);
				if(phoneChoice == 1 || phoneChoice == 2 || phoneChoice == 3){
				    choice = (enum phoneType) phoneChoice;
            P->type = (char*)calloc(MAX_TYPE_LEN + 1, sizeof(char));
				    char * type = (char*) calloc(MAX_TYPE_LEN + 1, sizeof(char));
				    switch(choice){
				        case Home:
				            strcpy(P->type, "Home");
				            break;
				        case Work:
				            strcpy(P->type, "Work");
				            break;
				        case Cell:
				            strcpy(P->type, "Cell");
				            break;
				        default:
				            printf("Invalid phone type entry, please try again\n");
				            break;
				    }
					break;
				}
			}
		}



    
  I = (ICD*)calloc(preset->c, sizeof(ICD));
  
    for (i = 0; i < preset[0].c;i++) 
      {
       

        while (true) 
        {
          printf("Enter ICD Code \n");
          memset(buffer, '\0', INPUT_BUFFER);
          scanf("%s", buffer);
          if (buffer[0] != '\0' && strlen(buffer) <= MAX_ICD_LEN) 
          {
           I[i].code = (char *)calloc(MAX_ICD_LEN + 1, sizeof(char));
            strcpy(I[i].code, buffer);
           I[0].code_Len = strlen(buffer);
            break;
          }
          else
            printf("Invalid ICD Code \n");
        }
        
      while (true) 
        {
          printf("Enter date (mm/dd/yy)\n");
          scanf("%u", &I[i].date);
          if (I[i].date != 0)
            break;
          else
            printf("\n\tError: Invalid date detected!");
        }
        
        }

  }

  if(!skip){
printf("Your first name is %s\n ", fname);
printf("Your last name is %s\n ", lname);
printf("Your street is %s\n ", sname);
printf("Your city name is %s\n ", city);
printf("Your state name is %s\n ", state);
printf(", zipcode is %i\n ", zip);
printf("%i\n ",FourDig);
printf("Your phone number is %d\n ", phoneN);
printf("Phone choice is %s\n ", P->type);
for(int i =0; i < MAX_ICD_ENT; i++){
  printf("ICD #: %s Date: %d/%d/%d\n ", I[i].code, I[i].date/10000,(I[i].date%10000)/100, (I[i].date%100) );
}
    }
  if(!load){
printf("Do you want to save this data?\n");
char userChoice;
    while ((getchar()) != '\n'); 
scanf("%c", &userChoice);
if(userChoice == 'Y'){
  fileNum++;
  idxPtr = fopen("ICD.idx", "w");
  fprintf(idxPtr, "%d", fileNum);
  fclose(idxPtr);
  sprintf(buffer, "%s_%s_%d.icd", lname, fname, fileNum);
  icdPtr = fopen(buffer, "w");

  fprintf(icdPtr, "%s\n",fname);
  fprintf(icdPtr, "%s\n", lname);
  fprintf(icdPtr, "%s\n", sname);
  fprintf(icdPtr, "%s\n", city);
  fprintf(icdPtr, "%s\n", state);
  fprintf(icdPtr, "%d\n", zip);
  fprintf(icdPtr, "%d\n", FourDig);
  fprintf(icdPtr, "%d\n", P->phoneNum);
  fprintf(icdPtr, "%s\n", P->type);

for(int i = 0; i <MAX_ICD_ENT; i++){
  fprintf(icdPtr, "%d\n", I[i].date);
  fprintf(icdPtr, "%s\n", I[i].code);
}
 fclose(icdPtr);
   printf("The record number is %d\n", fileNum);
    }
    }
free(fname);
free(lname);
free(sname);
free(I);

  }

  



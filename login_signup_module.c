#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct login_signup
{
	char username[100],email[100],dob[100];
	char mobile_no[100],pwd[100],retype_pwd[100],mob[100];
}user[100];
void sign_up();
void login();
void validate_username();
void validate_email();
void validate_password();
void validate_retype_password();
void validate_mobile_no();
void validate_dob();
int login_validate();
int i=0,k;
char temp_name[100],temp_email[100],temp_pwd[100],temp_repwd[100],lname[100],lpwd[100],temp_mob[100],temp_dob[100];
void login()
{
	printf("\tLOGIN\n");
	printf("Enter username: ");
	scanf("%s",&lname);
	printf("Enter password: ");
	scanf("%s",&lpwd);
	login_validate();
}
int login_validate()
{
	int k=0;
	while(k<=i)
	{
		if(!(strcmp(lname,user[k].username)))
		{
			if(!(strcmp(lpwd,user[k].pwd)))
			{
				printf("Welcome %s! Your login was successfull...\n\n",user[k].username);
				break;
			}
			else
			{
				printf("Login again and Please enter your correct password...\n");
				login();
				return 0;
			}
		}
		if(k==i)
		{
			printf("The username is not found...Please sign up to create an account..\n");
			sign_up();
			break;	
		}
		k++;
	}
}
void sign_up()
{
	printf("\tSIGN UP!\n");
	printf("Enter username: ");
	scanf("%s",&temp_name);
	strcpy(user[i].username,temp_name);
	validate_username();
	printf("Enter email id: ");
	scanf("%s",&temp_email);
	strcpy(user[i].email,temp_email);
	validate_email();
	printf("Enter password: ");
	scanf("%s",&temp_pwd);
	strcpy(user[i].pwd,temp_pwd);
	validate_password();
	printf("Retype password: ");
	scanf("%s",&temp_repwd);
	strcpy(user[i].retype_pwd,temp_repwd);
	validate_retype_password();
	printf("Enter mobile no: ");
	scanf("%s",&temp_mob);
	strcpy(user[i].mob,temp_mob);
	validate_mobile_no();
	printf("Enter dob in DD/MM/YYYY format: ");
	scanf("%s",&temp_dob);
	strcpy(user[i].dob,temp_dob);
	validate_dob();
	printf("Account created successfully...\n");
	i++;
}
void validate_username()
{
	int j=0;
	while(j<i && i!=j)
	{
		if(!(strcmp(temp_name,user[j].username)))
		{
			printf("The username already exits,enter some other username..\n\n");
			exit(0);
		}
		j++;
	}
}
void validate_email()
{
	int j=0,flag=0;
	if(strlen(temp_email)<5)
	{
		printf("Please enter valid email id...\n");
		exit(0);
	}
	while(j<i && i!=j)
	{
		if(!(strcmp(temp_email,user[j].email)))
		{
			printf("The email id already exits,enter some other email address..\n\n");
			exit(0);
		}
		j++;
	}
	j=0;
	while(temp_email[j]!='\0')
	{
		if(!(temp_email[j]>='A' && temp_email[j]<='Z'))
		{
			if(temp_email[j]=='@' && j>1 && (temp_email[j+1]>='a' && temp_email[j+1]<='z'))
				flag++;
			else if(temp_email[j]=='.' && (temp_email[j-1]>='a' && temp_email[j-1]<='z')&& (temp_email[j+1]>='a' && temp_email[j+1]<='z'))
				flag++;
		}
		else
		{
			printf("Please enter valid email with small letters..");
			exit(0);
		}
		j++;
	}
		if(flag!=2)
		{
				printf("Please enter valid email..");
				exit(0);
		}
}
void validate_password()
{
	int caps=0,small=0,spl_char=0,nums=0,k;
	if(strlen(temp_pwd)<8)
	{
		printf("Please enter password with minimum 8 characters...");
		exit(0);
	}
	for(k=0;temp_pwd[k]!='\0';k++)
	{
		if(temp_pwd[k]>='A' && temp_pwd[k]<='Z')
			caps++;
		if(temp_pwd[k]>='A' && temp_pwd[k]<='Z')
			small++;
		if(temp_pwd[k]>='0' && temp_pwd[k]<='9')
			nums++;
		if(temp_pwd[k]>=33 && temp_pwd[k]<=47 || temp_pwd[k]>=58 && temp_pwd[k]<=64)
			spl_char++;
	}
	if(caps==0 || nums==0 ||small==0 || spl_char==0)
	{
		printf("Enter valid password with special characters...");
		exit(0);
	}
}
void validate_retype_password()
{
	if(strcmp(temp_repwd,temp_pwd))
	{
		printf("The password doesn't matched...");
		exit(0);
	}
}
void validate_mobile_no()
{
	k=0;
	if(strlen(temp_mob)>12)
	{
		printf("Please enter valid mobile number..\n");
		exit(0);
	}	
	else
	{
		if((strlen(temp_mob)==11 && temp_mob[0]=='0')||(strlen(temp_mob)==10 && temp_mob[0]!='0')||(strlen(temp_mob)==12 && (temp_mob[0]=='9' && temp_mob[1]=='1')))
		{
			while(temp_mob[k]!='\0')
			{
				if(!(temp_mob[k]>='0' && temp_mob[k]<='9'))
					break;
				k++;
			}
			if(k!=strlen(temp_mob))
			{
				printf("Please enter valid mobile number...\n");
				exit(0);
			}
		}
		else
		{
			printf("Please enter valid mobile number...\n");
			exit(0);
		}
	}
}

void validate_dob()
{
	int mm,dd,yy,age,present_date=06,present_mm=04,present_yy=2021;
	if((strlen(temp_dob)==10))
	{
		dd=((temp_dob[0]-'0')*10)+(temp_dob[1]-'0');
		mm=((temp_dob[3]-'0')*10)+(temp_dob[4]-'0');
		yy=((temp_dob[6]-'0')*1000)+((temp_dob[7]-'0')*100)+((temp_dob[8]-'0')*10)+((temp_dob[9]-'0'));
		if((yy>1900 && yy<2022) && (mm>0 && mm<=12))
		{
			if(mm==2)
			{
				if(yy%4==0 || (yy%100==0 && yy%400==0))
        		{
            		if(!(dd>0 && dd<=29))
            		{
                		printf("Date Invalid");
                		exit(0);
           	 		}	
          		}
        		else
        		{
            		if(!(dd>0 && dd<=28))
            		{
                		printf("Date Invalid");
                		exit(0);
            		}
            	}
			}
			else if(!(((mm==1 || mm==3 ||mm==5 ||mm==7|| mm==8 || mm==10 || mm==12)&& (dd>=1 && dd<=31))||((mm==4||mm==6||mm==9||mm==11)&& (dd>=1 &&dd<=30))))
			{
				printf("Please enter valid date...");
				exit(0);
			}			
			if(mm>present_mm)
				present_yy-=1;
			age=present_yy-yy;
			printf("Age : %d\n",age);
		}
		else
		{
			printf("Please enter valid dob...");
			exit(0);
		}
	}
	else
	{
		printf("Please enter dob in dd/mm/yyyy format...");
		exit(0);
	}
}
int main()
{
	int choice;
	printf("\tLOGIN SIGNUP PAGE\n");
	while(1)
	{
		printf("\n1.Sign up\n2.Login\n3.Exit\n");
		printf("Enter choice for sign up or login: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{		
			case 1: 
			{
				sign_up();
				break;
			}
			case 2:
			{
				login();
				break;		
			}
			case 3:
			{
				exit(1);
				break;
			}
			default:
			{
				printf("Invalid choice");
				break;
			}
		}
	}
	return 0;
}

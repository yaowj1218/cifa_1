#include<iostream>
int i = 0;
int end = 0;
char* kind = (char *)malloc(sizeof(char) * 100);
char* stack = (char *)malloc(sizeof(char) * 20);
char* keywords[14] = { "int","char","void","if","else","swich","case","default","while","do","for","break","continue","return" };
void myscanf(char* str) {
	int i = 0;
	char c;
	do {
		c = getchar();
		if (c == '#') break;
		*(str + i) = c;
		i++;
	} while (1);
	*(str + i) = '\0';
}

void fenxi(char* str) {
	int j = 0;
	end = 0;
	char ch;
	//------------------------------------------清空 stack
	for (int m = 0; m<20; m++) {
		stack[m] = NULL;
	}
	ch = str[i++];
	//-------------------------------------------去空格
	while (ch == ' '|| ch == '\n') { ch = str[i++]; }
	//while (ch == '\n') { ch = str[i++]; }
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			stack[j++] = ch;
			ch = str[i++];
		}
		stack[j] = '\0';
		i--;
		kind = "id";
		//-------------------------------------------keyword
		for (int k = 0; k < 14; k++) {
			if (strcmp(stack, keywords[k]) == 0) {
				kind = "key word";
				break;
			}
		}
	}
	else if (ch >= '0'&&ch <= '9') {
		if (ch == '0') {
			stack[j++] = ch;
			ch = str[i++];
			if (ch == 'x') {
				stack[j++] = ch;
				ch = str[i++];
				if (!(ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f')) {
					end = 1;
					while (!(str[i] =='\0'|| str[i] ==' ')) {
						ch = str[i++];
					}
					//i--;
				}
				else {
					while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f')) {
					if (!(ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'f')) {
						end = 1;
						while (!(str[i] == '\0' || str[i] == ' ')) {
							ch = str[i++];
						}
						//i--;
						break;
					}
					stack[j++] = ch;
					ch = str[i++];
					
				}
				stack[j] = '\0';
				i--;
				kind = "十六进制数字常量";
				}
				
			}
			else {
				stack[j++] = ch;
				
				if (!(ch >= '0'&&ch <= '7')) {
					end = 1;
					while (!(str[i] == '\0' || str[i] == ' ')) {
						ch = str[i++];
					}
				}
				else {
					ch = str[i++];
					while ((ch >= '0'&&ch <= '7')) {
						if (!(ch >= '0'&&ch <= '7')) {
							end = 1;
							while (!(str[i] == '\0' || str[i] == ' ')) {
								ch = str[i++];
							}
							break;
						}
						stack[j++] = ch;
						ch = str[i++];
					}
					stack[j] = '\0';
					i--;
					kind = "八进制数字常量";
				}
			}
		}
		else {
			stack[j++] = ch;
		
			if (!(ch >= '0'&&ch <= '9')) {
				end = 1;
				while (!(str[i] == '\0' || str[i] == ' ')) {
					ch = str[i++];
				}
			}
			else {	
				ch = str[i++];
				while ((ch >= '0'&&ch <= '9')) {
					if (!(ch >= '0'&&ch <= '9')) {
						end = 1;
						while (!(str[i] == '\0' || str[i] == ' ')) {
							ch = str[i++];
						}
						break;
					}
					stack[j++] = ch;
					ch = str[i++];
				}
				stack[j] = '\0';
				i--;
				kind = "十进制数字常量";
			}
		}

	}
	else if (ch == '\'' || ch == '\"') {
		if (ch == '\'') {
			ch = str[i++];
			stack[j++] = ch;
			if (str[i] != '\'') {
				end = 1;
				return;
			}
			stack[j] = '\0';
			i++;
			kind = "字符";
		}
		else {
			if (ch == '\"')
				ch = str[i++];
			while (ch != '\"') {
				stack[j++] = ch;
				ch = str[i++];
				if (ch == '\0') {
					end = 1;
					return;
				}
			}
			stack[j] = '\0';
			kind = "字符串";
		}
	}
	else switch (ch) {


	case '+':
		if (str[i] == '+') {
			stack[j++] = ch;
			ch = str[i];
			stack[j] = ch;
			kind = "运算符";
		}
		else {
			kind = "运算符";
			stack[0] = ch;
		}break;



	case '-':
		if (str[i] == '-') {
			stack[j++] = ch;
			ch = str[i];
			stack[j] = ch;
			kind = "运算符";
		}
		else {
			kind = "运算符";
			stack[0] = ch;
		}break;



	case '*': kind = "运算符"; stack[0] = ch; break;



	case '/': kind = "运算符"; stack[0] = ch; break;



	case '=':if (str[i] == '-') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";
	}
			 else {
				 kind = "运算符";
				 stack[0] = ch;
			 }break;



	case '%': kind = "运算符"; stack[0] = ch; break;



	case '!':  if (str[i] == '=') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";                       //
	}
			   else {
				   kind = "运算符";
				   stack[0] = ch;
			   }break;



	case '<':  if (str[i] == '=') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";                        //
	}
			   else {
				   kind = "运算符";
				   stack[0] = ch;
			   }break;



	case '>':  if (str[i] == '=') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";                    //
	}
			   else {
				   kind = "运算符";
				   stack[0] = ch;
			   }break;



	case '&':  if (str[i] == '&') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";                       //
	}break;



	case '|':  if (str[i] == '|') {
		stack[j++] = ch;
		ch = str[i];
		stack[j] = ch;
		kind = "运算符";                        //
	}break;


	case ',': kind = "分界符"; stack[0] = ch; break;
	case ':': kind = "分界符"; stack[0] = ch; break;
	case ';': kind = "分界符"; stack[0] = ch; break;
	case '(': kind = "分界符"; stack[0] = ch; break;
	case ')': kind = "分界符"; stack[0] = ch; break;
	case '{':kind = "分界符"; stack[0] = ch; break;
	case '}': kind = "分界符"; stack[0] = ch; break;

	}

}
int main() {
	char *str = (char *)malloc(sizeof(char) * 100);
	myscanf(str);
	while (*(str + i) != '\0'&&end == 0) {
		fenxi(str);
		if (end == 0)
			printf("< %s ,  %s >\n", kind, stack);
		else
			printf("ERROR\n");
		end = 0;
	}
	printf("str: %s \n", str);
	getchar();
	system("pause");
	return 0;
}

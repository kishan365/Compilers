#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

typedef struct tokenAndVal {
	int value[20];
	tokentype type[20];
}tokenAndVal;
typedef enum
{
	ParserState_operator,
	ParserState_operand
}Parser_state;

typedef enum {
	exprStatus_confirmed,
	exprStatus_notconfirmed
}exprStatus;

void parseExpression(char* input, int* pos,tokenAndVal *typeAndVal,static int *num_start) {
	int state = ParserState_operand;
	static int bracket=0;
	int num_value;
	token t;
	static int start = 0;
	*num_start = 0;
	for (int i = 0; input[*pos] != 0; i++) {
		int active_token = 0;
		tokenize(input+*pos, pos, &t);
		if (state == ParserState_operand) {
			if (t.token_type == tokentype_Var) {
				printf("Var Operand:%s\n", t.text);
				state = ParserState_operator;
			}
			else if (t.token_type == tokentype_Num) {
				typeAndVal->value[*num_start] = stringToNum(t.text);
				printf("Num Operand:%s\n", t.text);
				state = ParserState_operator;
				*num_start = *num_start+1;
			}
			else if (t.token_type == tokentype_Add) {
				printf("Add Unary Operator:%s\n", t.text);
			}
			else if (t.token_type == tokentype_Sub) {
				printf("Sub Unary Operator:%s\n", t.text);
			}
			else if (t.token_type == tokentype_LBar) {  
				bracket++;
				printf("Open bracket:%s\n", t.text);
				parseExpression(input, pos,typeAndVal,num_start);

			}
			else {
				printf("Error\n");
				exit(-1);
			}
		}
		else if (state == ParserState_operator) {
			if (t.token_type == tokentype_Add) {
				active_token = 1;
				printf("Add Binary Operator:%s\n", t.text);
				state = ParserState_operand;
			}
			else if (t.token_type == tokentype_Sub) {
				active_token = 1;
				printf("Sub Binary Operator:%s\n", t.text);
				state = ParserState_operand;
			}
			else if (t.token_type == tokentype_Mul) {
				active_token = 1;
				printf("Mul Binary Operator:%s\n", t.text);
				state = ParserState_operand;
			}
			else if (t.token_type == tokentype_Div) {
				active_token = 1;
				printf("Div Binary Operator:%s\n", t.text);
				state = ParserState_operand;
			}
			else if (t.token_type == tokentype_Equal) {
				printf("Assignment operator:%s", t.text);
				state == ParserState_operand;
			}

			else {
				if (t.token_type == tokentype_RBar && bracket >0) {
					bracket--;
					printf("close bracket:%s\n", t.text);
				}
				else {
					printf("Error\n");
					exit(-1);
				}
			}
			if (active_token == 1) {
				
				typeAndVal->type[start] = t.token_type;
				start++;
			}
		}
	}
	if (bracket != 0) {
		printf("Error");
		exit(1);
	}
}
int stringToNum(char* string) {
	int value = 0;
	int iter;
	int times = 1;
	for (iter = 0; string[iter] != '\0'; iter++) {

	}
	for (int i = iter - 1; i >= 0; i--) {
		value = value + (((int)string[i]) - '0') * times;
		times = times * 10;
	}
	return value;
}

int main() {
	tokenAndVal typeAndVal;
	char* string = "3+5+4*90";  
	int pos = 0;
	int result=0;
	int count;
	parseExpression(string, &pos,&typeAndVal,&count);
	for (int i = 0; i < count-1; i++) { 

		if (typeAndVal.type[i] == tokentype_Add && i==0) {
			result = result + typeAndVal.value[i] + typeAndVal.value[i + 1];
		}
		else if (typeAndVal.type[i] == tokentype_Sub && i==0) {
			result = result + typeAndVal.value[i] - typeAndVal.value[i+1];
		}
		else if (typeAndVal.type[i] == tokentype_Add) {
			result = result + typeAndVal.value[i + 1];
		}
		else if (typeAndVal.type[i] == tokentype_Sub) {
			result = result - typeAndVal.value[i + 1];
			 
		}
		else {
			printf("The operator is undefined\n");
		}
	}
	printf("The value is: %d", result);
	return 0;
}


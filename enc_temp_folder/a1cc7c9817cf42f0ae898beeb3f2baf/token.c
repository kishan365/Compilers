#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

// typedef struct parameterInfo {
// 	int value;
// 	tokentype type;
// }parameterInfo;
// typedef enum
// {
// 	parse_operator,
// 	parse_operand
// }Parser_state;

// typedef enum {
// 	exprStatus_confirmed,
// 	exprStatus_notconfirmed
// }exprStatus;

// int calculteResult(parameterInfo *p, int num_count) {
// 	int i = 0;
// 	int result = 0;
// 	for (int i = 0; i < num_count; i++) {
// 		if (p[i].type == tokentype_Add && i==0) {
// 			result = result + p[i].value + p[i + 1].value;
// 		}
// 		else if (p[i].type == tokentype_Sub && i==0) {
// 			result = result + p[i].value - p[i + 1].value;
// 		}
// 		else if (p[i].type == tokentype_Add) {
// 			result = result + p[i + 1].value;
// 		}
// 		else if (p[i].type == tokentype_Sub) {
// 			result = result - p[i + 1].value;
// 		}
// 		else if (p[i].type == tokentype_Error) {
// 			return result;
// 		}
// 		else {
// 			printf("The operator is either invalid or is not supported in this calulator\n");
// 		}
// 	}
// 	return result;
	
// }

// int checkGrammer(token t, int *state, int *bracket) {
// 	if (*state == parse_operand) {
// 		if (t.token_type == tokentype_Var) {
// 			printf("Identifier:%s\n", t.text);
// 			*state = parse_operator;
// 		}
// 		else if (t.token_type == tokentype_Num) {
// 			printf("Number:%s\n", t.text);
// 			*state = parse_operator;
// 		}
// 		else if (t.token_type == tokentype_Add) {
// 			printf("Urinary Add:%s\n", t.text);
// 		}
// 		else if (t.token_type == tokentype_Sub) {
// 			printf("Urinary Sub:%s\n", t.text);
// 		}
// 		else if (t.token_type == tokentype_LBar) {
// 			*bracket = *bracket + 1;
// 			printf("Open Bracket:%s\n", t.text);
// 		}

// 		else {
// 			printf("Error\n");
// 			return 0;
// 		}
// 	}
// 	else if (*state == parse_operator) {
// 		if (t.token_type == tokentype_Add) {
// 			printf("Add:%s\n", t.text);
// 			*state = parse_operand;
// 		}
// 		else if (t.token_type == tokentype_Sub) {
// 			printf("Sub:%s\n", t.text);
// 			*state = parse_operand;
// 		}
// 		else if (t.token_type == tokentype_Mul) {
// 			printf("Multiply:%s\n", t.text);
// 			*state = parse_operand;
// 		}
// 		else if (t.token_type == tokentype_Div) {
// 			printf("Divide:%s\n", t.text);
// 			*state = parse_operand;
// 		}
// 		else if (t.token_type == tokentype_RBar) {
// 			*bracket = *bracket - 1;
// 			printf("Close Bracket:%s\n", t.text);
// 		}
		
// 		else {
// 			printf("Error\n");
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
// checkToken(token* t, char *input,int *pos,int size, int *state, int *bracket) {
// 	tokenize(input + *pos, pos, t);
// 	if (!checkGrammer(*t, state, bracket)) {
// 		printf("Error\n");
// 		exit(-1);
// 	}
// }
// int isCallingTokenizeValid(char* input, int* pos, token* t,int size) {
// 	if (*pos < size) {
// 		tokenize(input + *pos, pos, t);
// 		return 1;
// 	}
// 	else {
// 		return 0;
// 	}
// }

// void parseExpression(char* input, int* pos, int size) {
// 	int state = parse_operand;
// 	int result;
// 	int prior_result = 1;
// 	parameterInfo parameter[10];
// 	token t;
// 	int num_count = 0;
// 	int bracket = 0;	//for tracking the opening and closing bracket;
// 	for (int i = 0; i < size; i++) {
// 		checkToken(&t, input, pos, size, &state, &bracket);
// 	}
// 	if (bracket != 0) {
// 		printf("Mismatch in the brackets\n");
// 		exit(-1);
// 	}
// 	*pos = 0;
// 	for (int iter = 0; iter < 10; iter++) {
// 		memset(&parameter[iter], '\0', sizeof(parameter)/10);
// 	}
// 	for (int i=0, iter = 0; iter < size; iter++ ) {
// 		if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 			result = calculteResult(parameter, num_count);
// 			break;
// 		}
// 		if (t.token_type == tokentype_Num) {
// 			num_count++;
// 			if(!isCallingTokenizeValid(input, pos, &t, size)){
// 				result = calculteResult(parameter, num_count);
// 				break;
// 			}
// 			if (t.token_type == tokentype_Mul || t.token_type == tokentype_Div) {
// 				//while (t.token_type == tokentype_Mul || t.token_type == tokentype_Div) {}
// 				if (t.token_type == tokentype_Mul) {
// 					*pos = *pos - 2;
// 					if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 						result = calculteResult(parameter, num_count);
// 						break;
// 					}
// 					prior_result = prior_result * stringToNum(t.text);
// 					*pos = *pos + 1;
// 					if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 						result = calculteResult(parameter, num_count);
// 						break;
// 					}
					
// 					prior_result = prior_result * stringToNum(t.text);
// 					parameter[i].value = prior_result;
// 					prior_result = 1;
// 					continue;

// 				}
// 				if (t.token_type == tokentype_Div) {
// 					*pos = *pos - 2;
// 					if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 						result = calculteResult(parameter, num_count);
// 					}
// 					prior_result = prior_result * stringToNum(t.text);
// 					*pos = *pos + 1;
// 					if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 						result = calculteResult(parameter, num_count);
// 						break;
// 					}
// 					prior_result = prior_result / stringToNum(t.text);
// 					parameter[i].value = prior_result;
// 					prior_result = 1;
// 					continue;
// 			}
// 			}
// 			*pos = *pos - 2;
// 			if (!isCallingTokenizeValid(input, pos, &t, size)) {
// 				result = calculteResult(parameter, num_count);
// 				break;
// 			}
// 			parameter[i].value = stringToNum(t.text);
			
// 		}
// 		else if (t.token_type == tokentype_Add) {
// 			parameter[i].type = t.token_type;
// 			i++;
// 		}
// 		else if (t.token_type == tokentype_Sub) {
// 			parameter[i].type = t.token_type;
// 			i++;
// 		}
		
// 		else {
// 			printf("Error: Something looks suspicious\n");
// 			return 0;
// 		}
		
// 	}
// 	result = calculteResult(parameter, num_count);
// 	printf("The result is:%d\n", result);
// }

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

int parseOperand(tokenizer* tzer, int *result) {
	token t;
	if (tokenize(tzer, &t)) {
		if (t.token_type == tokentype_Num) {
			printf("number: %s\n", t.text);
			*result = stringToNum(t.text);
		}
		else if (t.token_type == tokentype_Var) {
			printf("var: %s\n", t.text);
			*result = 0; // unsupported
		}
		else {
			printf("expected number/var/unary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

int parsePrimaryExpression(tokenizer *tzer, int *result) {
	token t;
	if (tokenize(tzer, &t)) {
		int sign = 1;

		if (t.token_type == tokentype_Add) {
			printf("unary: %s\n", t.text);
			if (!tokenize(tzer, &t)) {
				printf("expected operand\n");
				exit(1);
			}
		}
		else if (t.token_type == tokentype_Sub) {
			sign = -1;
			printf("unary: %s\n", t.text);
			if (!tokenize(tzer, &t)) {
				printf("expected operand\n");
				exit(1);
			}
		}

		if (t.token_type == tokentype_Num) {
			printf("number: %s\n", t.text);
			*result = sign * stringToNum(t.text);
		}
		else if (t.token_type == tokentype_Var) {
			printf("var: %s\n", t.text);
			*result = 0; // unsupported
		}
		else {
			printf("expected number/var/unary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

typedef enum binaryOperator {
	binaryOperator_Add,
	binaryOperator_Sub,
	binaryOperator_Mul,
	binaryOperator_Div,
}binaryOperator;

int parseBinaryOperator(tokenizer *tzer, binaryOperator *op) {
	token t;
	if (tokenize(tzer, &t)) {
		if (t.token_type == tokentype_Add) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Add;
		}
		else if (t.token_type == tokentype_Sub) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Sub;
		}
		else if (t.token_type == tokentype_Mul) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Mul;
		}
		else if (t.token_type == tokentype_Div) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Div;
		}
		else {
			printf("expected binary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

int evaluateExpression(int left, binaryOperator op, int right) {
	switch (op)
	{
		case binaryOperator_Add: return left + right;
		case binaryOperator_Sub: return left - right;
		case binaryOperator_Mul: return left * right;
		case binaryOperator_Div: return left / right;
	}
	return 0;
}
//lets dont change any logic and now just sort the input such that the multiply and divide will
//will be in the leftmost side

void sortInput(char** input1, int size) {
	char temp;
	int alter = 1;
	char* input2;
	input2 = (char*)malloc(size * 2);
	int i = 0;
	int count = 4;
	int sign = 0;
	int flag = 0;
	if (input1[0][0] != '-') {
		if (!(input1[0][1] == '+' || input1[0][1] == '-')) {
			input2 = input2 + 3;
			flag = 1;
		}
	}
	else {
		if (input1[0][2] != '+' || input1[0][2] != '-') {
			input2 = input2 + 4;
			sign = 1;
			flag = 1;
		}
	}
	for (int iter2 = 0; iter2 < size; iter2++) {
		if ((input1[0][iter2] == '*' || input1[0][iter2] == '/')) {
			while (input1[0][iter2 + 2] == '*' || input1[0][iter2 + 2] == '/') {
				count = count + 2;
				iter2 = iter2 + 2;
			}
			iter2 = iter2 - count + 4;
			for (; i < count; i++) {
				input2[i] = input1[0][iter2 - 2 + i];
				if (alter) {
					input1[0][iter2 - 2 + i] = '+';
					alter = 0;
				}
				else {
					input1[0][iter2 - 2 + i] = '0';
					alter = 1;
				}
			}
		}
		
	}
	for (int j = 0; j < size; j++,i++) {
		if (input1[0][0] != '-' && j==0) {
			input2[i] = '+';
			i++;
			input2[i] = input1[0][j];
		}
		else {
			input2[i] = input1[0][j];
		}
	}
	input2[i] = '/0';
	if (sign && flag) {
		input2 = input2 - 4;
	}
	else if(flag) {
		input2 = input2 - 3;
	}
	*input1 = input2;
	input1[0][i] = '\0';
	
}
int main() {
	char input[] = "4*2+3*2";
	tokenizer tzer;
	
	

	token t;

	// œ cal add/sub
	// bracket
	// cal mul/div
	// var support

	// œ primary expr
	// œ binary operator
	// primary expr
	// operator

	int left = 0;
	int size = strlen(input);
	char* input1 = input;
	sortInput(&input1, size);
	tzer.start = input1;
	tzer.pos = 0;
	
	if (parsePrimaryExpression(&tzer, &left)) {
		while (1) {
			binaryOperator op;
			if (!parseBinaryOperator(&tzer, &op)) {
				break;
			}
			int right = 0;
			if (!parseOperand(&tzer, &right)) {
				printf("expected primary expression\n");
				exit(1);
			}

			left = evaluateExpression(left, op, right);
		}
	} else {
		printf("empty input\n");
	}

	printf("result: %d\n", left);
}


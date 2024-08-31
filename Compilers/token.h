#pragma once
#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H
#endif // !MATHLIBRARY_H

#define max_size 20

typedef enum {
	tokentype_Error,
	tokentype_Var,
	tokentype_Num,
	tokentype_Add,
	tokentype_Sub,
	tokentype_Mul,
	tokentype_Div,
	tokentype_Equal,
	tokentype_Space,
	tokentype_LBar,
	tokentype_RBar,
	tokentype_COUNT

}tokentype;

static const char* TokenNames[] = {
	"error","var", "num", "add", "sub", "mul", "div", "equal", "space"
};

typedef enum {
	chartype_error,
	chartype_Char,
	chartype_Num,
}chartype;

typedef struct {
	char text[max_size];
	tokentype token_type;
}token;

typedef struct {
	token* t;
	struct token_lists* next;
}token_lists;



void printtokentype(token t) {
	printf("%s:%s\n", TokenNames[t.token_type], t.text);
}

int isNum(char c) {
	return (c >= '0' && c <= '9');
}

int isVar(char c) {
	return (c == '_' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}


void tokenize(char* input, int* pos, token* t) {
	//Pahila jun jun sajilo xa tyo tyo suru ma garihalum kina vane tyo garna sajilo hunxa
	//hamile position pos vanne variable pani linxau kinavane tesle hami string ma ka xau vanne kura dekhauxa but as for now we are going to take the position variable only as a simple variable 
	//a+b this is a  4545454567876496753 ? 56/34

	while (input[0] == ' ') {
		*pos = *pos + 1;
		input++;
	}


	if (input[0] == '+') {
		t->token_type = tokentype_Add;
		t->text[0] = '+';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == '-') {
		t->token_type = tokentype_Sub;
		t->text[0] = '-';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == '*') {
		t->token_type = tokentype_Mul;
		t->text[0] = '*';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == '/') {
		t->token_type = tokentype_Div;
		t->text[0] = '/';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == '=') {
		t->token_type = tokentype_Equal;
		t->text[0] = '=';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == '(') {
		t->token_type = tokentype_LBar;
		t->text[0] = '(';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (input[0] == ')') {
		t->token_type = tokentype_RBar;
		t->text[0] = ')';
		t->text[1] = 0;
		*pos = *pos + 1;
		return;
	}
	else if (isNum(input[0])) {
		int start = 1;
		*pos = *pos + 1;
		while (isNum(input[start])) {
			*pos = *pos + 1;
			start++;

		}

		//*pos = *pos - 1;
		int length = start;
		/*if (input[*pos] != ' ') {
			*pos = *pos - 1;
		}*/
		for (int i = 0; i < length; i++) {
			t->text[i] = input[i];
			start++;
		}
		t->text[length] = 0;
		t->token_type = tokentype_Num;
		return;
	}
	else if (isVar(input[0])) {
		int start = 1;
		*pos = *pos + 1;
		while (isVar(input[start])) {
			*pos = *pos + 1;
			start++;
		}


		int length = start;
		/*if (input[*pos] != ' ') {
			*pos = *pos - 1;

		}*/
		for (int i = 0; i < length; i++) {
			t->text[i] = input[i];
			start++;
		}

		t->text[length] = 0;
		t->token_type = tokentype_Var;
		return;
	}
	else {
		int i;

		for (i = 0; input[i] != ' '; i++) {
			t->text[i] = input[i];
			*pos = *pos + 1;
		}
		//*pos = *pos - 1;
		t->text[i] = 0;
		t->token_type = tokentype_Error;
		return;
	}
}
//Lets create a linked structure of the tokens 
token_lists* insertToken(token_lists* head, token_lists* new_token, token* tok) {
	token_lists* start = head;
	while (start->next != NULL) {
		start = start->next;
	}
	start->next = new_token;
	start = start->next;
	start->t = tok;
	start->next = NULL;

}

void printTokenList(token* t, int size) {
	for (int i = 0; i < size; i++) {
		printf("%s:%s\n", t[i].text, TokenNames[t[i].token_type]);
	}
}

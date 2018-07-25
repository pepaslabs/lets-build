#include <stdlib.h> // for EXIT_SUCCESS, etc.
#include <stdio.h> // for printf(), perror(), etc.
#include <string.h> // for memset(), etc.
#include <stdbool.h>

enum token_type_t_ {
    START_TAG = 0,
    END_TAG = 1,
    EMPTY_TAG = 2,
    END_OF_TOKENS = -1
};
typedef enum token_type_t_ token_type_t;

char *token_names[] = {"start", "end", "empty"};

struct token_t_ {
    token_type_t type;
    char *start;
    char *end;
};
typedef struct token_t_ token_t;

bool recognize_start_tag(char *input, token_t *token) {
    char *start = NULL;
    char *end = NULL;

    // check the opening bracket:
    if (*input == '<') {
        start = input;
    } else {
        return false;
    }

    // search for the closing bracket:
    while (*input != '\0') {
        if (*input == '>') {
            end = input;
            break;
        } else {
            input++;
        }
    }

    if (start != NULL && end != NULL) {
        // we recognized a token
        token->type = START_TAG;
        token->start = start;
        token->end = end;
        return true;
    } else {
        return false;
    }
}

bool recognize_end_tag(char *input, token_t *token) {
    char *start = NULL;
    char *end = NULL;

    // check the opening bracket:
    if (*input == '<') {
        start = input;
    } else {
        return false;
    }

    input++;
    // check the slash:
    if (*input != '/') {
        return false;
    }

    // search for the closing bracket:
    while (*input != '\0') {
        if (*input == '>') {
            end = input;
            break;
        } else {
            input++;
        }
    }

    if (start != NULL && end != NULL) {
        // we recognized a token
        token->type = END_TAG;
        token->start = start;
        token->end = end;
        return true;
    } else {
        return false;
    }
}

bool recognize_empty_tag(char *input, token_t *token) {
    char *start = NULL;
    char *end = NULL;

    // check the opening bracket:
    if (*input == '<') {
        start = input;
    } else {
        return false;
    }

    // search for the closing bracket and slash:
    while (*input != '\0') {
        if (*input == '>') {
            if (*(input-1) != '/') {
                return false;
            }
            end = input;
            break;
        } else {
            input++;
        }
    }

    if (start != NULL && end != NULL) {
        // we recognized a token
        token->type = EMPTY_TAG;
        token->start = start;
        token->end = end;
        return true;
    } else {
        return false;
    }
}

bool recognize(char *input, token_t *token) {
    return recognize_end_tag(input, token)
        || recognize_empty_tag(input, token)
        || recognize_start_tag(input, token)
        || false;
}

bool tokenize(char *input, token_t *output) {
    while (*input != '\0' && output->type != END_OF_TOKENS) {
        if (recognize(input, output)) {
            input = output->end + 1;
            output++;
        } else {
            output->type = END_OF_TOKENS;
            return false;
        }
    }

    output->type = END_OF_TOKENS;
    return true;
}

void print_tokens(token_t *tokens) {
    token_t *current = tokens;
    while(current->type != END_OF_TOKENS) {
        printf("%s\n", token_names[current->type]);
        current++;
    }
}

char buffer[10 * 1024 + 1];

token_t tokens[1024 + 1];
unsigned int token_count = 0;

int main(void) {
    // Read up to 10k from stdin.
    fread(buffer, sizeof(char), sizeof(buffer), stdin);
    if (ferror(stdin)) {
        perror("Error reading from stdin");
        return EXIT_FAILURE;
    }

    // Ensure the tokens array starts off zeroed and "Null-terminated".
    memset(tokens, 0, sizeof(tokens));
    token_t *last_token = tokens + (sizeof(tokens) / sizeof(token_t)) - 1;
    last_token->type = END_OF_TOKENS;

    bool ret = tokenize(buffer, tokens);
    print_tokens(tokens);
    if (ret == false) {
        fprintf(stderr, "Error: unrecognized input\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

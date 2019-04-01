#include<stdio.h>
#include<string.h>
#include<stack>
#include<string>
#include<iostream>
#define SIZE 50

using namespace std;
char s[SIZE];
int top=-1;


int hasPrecedence(char op1, char op2)
{
    if (op2 == '(' || op2 == ')')
        return 0;
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return 0;
    else
        return 1;
}


int applyOp(char op, int b, int a)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Cannot divide by zero");
            return 0;
        }
        else
        {
            return a / b;
        }

    }
    return 0;
}

int getValue(string expression)
{
    //cout<<"Expression : "<<expression<<endl;
    string tokens = expression;
    stack<int>values;
    stack<char>ops;
    for(int i=0; i<tokens.size(); i++)
    {
        //if(tokens.at(i)==' ')
            //continue;

        if(tokens.at(i) >= '0' && tokens.at(i) <= '9')
        {
            int value=0;
            while((i < tokens.size()) && (tokens.at(i) >= '0') && (tokens.at(i) <= '9'))
            {
                value = (value*10) + (tokens.at(i)-'0');
                i++;
            }
            values.push(value);
        }
        else if (tokens.at(i) == '(')
            ops.push(tokens.at(i));
        else if (tokens.at(i) == ')')
        {
            while (ops.top() != '(')
            {
                char c = ops.top();
                ops.pop();
                int a = values.top();
                values.pop();
                int b = values.top();
                values.pop();
                values.push(applyOp(c,a,b));
            }
            ops.pop();
        }
        else if (tokens.at(i) == '+' || tokens.at(i) == '-' || tokens.at(i) == '*' || tokens.at(i) == '/')
        {
            while (!ops.empty() && hasPrecedence(tokens.at(i), ops.top()))
            {
                char c = ops.top();
                ops.pop();
                int a = values.top();
                values.pop();
                int b = values.top();
                values.pop();
                values.push(applyOp(c,a,b));
            }
            ops.push(tokens.at(i));
        }
    }
    while (!ops.empty())
    {
        char c = ops.top();
        ops.pop();
        int a = values.top();
        values.pop();
        int b = values.top();
        values.pop();
        values.push(applyOp(c,a,b));
    }

    if(values.empty())
    {
        return 0;
    }
    else
    {
        return values.top();
    }
}

push(char elem)
{
    /* Function for PUSH operation */
    s[++top]=elem;
}

char pop()
{
    /* Function for POP operation */
    return(s[top--]);
}

int pr(char elem)
{
    /* Function for precedence */
    switch(elem)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}
infix_to_prefix()
{
    getchar();
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("Enter the Infix expression: ");
    gets(infx);
    string str(infx);
    string new_str;
    for(int i = 0; i<str.size(); i++)
    {
        if((str.at(i)>='a'&&str.at(i)<='z')||(str.at(i)>='A'&&str.at(i)<='Z'))
        {
            int num;
            char s[100];
            cout<<str.at(i)<<" = ";
            cin>>num;
            sprintf(s,"%d",num);
            for(int a=0; a<strlen(s); a++)
            {
                new_str.push_back(s[a]);
            }
        }
        else
        {
            new_str.push_back(str.at(i));
        }
    }
    if(!new_str.empty())
    {
        cout<<"\nEquivalent Mathematical Expression: "<<new_str<<endl;
    }


    int c = 0;
    for (int i = 0; infx[i]; i++)
        if (infx[i] != ' ')
            infx[c++] = infx[i];
    infx[c] = '\0';
    push('#');
    char temp;
    i = 0;
    int j = strlen(infx) - 1;
    while (i < j)
    {
        temp = infx[i];
        infx[i] = infx[j];
        infx[j] = temp;
        i++;
        j--;
    }
    i=0,k=0;
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')')
            push(ch);
        else if(isalnum(ch))
            prfx[k++]=ch;
        else if( ch == '(')
        {
            while( s[top] != ')')
                prfx[k++]=pop();
            elem=pop(); /* Remove ) */
        }
        else
        {
            /* Operator */
            while( pr(s[top]) >= pr(ch) )
                prfx[k++]=pop();
            push(ch);
        }
    }
    while( s[top] != '#')     /* Pop from stack till empty */
        prfx[k++]=pop();
    prfx[k]='\0';          /* Make prfx as valid string */

    i = 0;
    j = strlen(prfx) - 1;
    while (i < j)
    {
        temp = prfx[i];
        prfx[i] = prfx[j];
        prfx[j] = temp;
        i++;
        j--;
    }

    i = 0;
    j = strlen(infx) - 1;
    while (i < j)
    {
        temp = infx[i];
        infx[i] = infx[j];
        infx[j] = temp;
        i++;
        j--;
    }
    printf("Corresponding Prefix Expression: %s\n",prfx);
    cout<<"Mathematical Result: "<<getValue(new_str)<<endl;
}

int priority(char x)
{
    switch(x)
    {
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}

infix_to_postfix()
{
    getchar();
    char exp[20];
    char *e, x;
    printf("Enter the Infix expression: ");
    gets(exp);
    string str(exp);
    string new_str;
    for(int i = 0; i<str.size(); i++)
    {
        if((str.at(i)>='a'&&str.at(i)<='z')||(str.at(i)>='A'&&str.at(i)<='Z'))
        {
            int num;
            char s[100];
            cout<<str.at(i)<<" = ";
            cin>>num;
            sprintf(s,"%d",num);
            for(int a=0; a<strlen(s); a++)
            {
                new_str.push_back(s[a]);
            }
        }
        else
        {
            new_str.push_back(str.at(i));
        }
    }
    if(!new_str.empty())
    {
        cout<<"\nEquivalent Mathematical Expression: "<<new_str<<endl;
    }

    int c = 0;
    for (int i = 0; exp[i]; i++)
        if (exp[i] != ' ')
            exp[c++] = exp[i];
    exp[c] = '\0';
    e = exp;
    printf("Corresponding Postfix Expression: ");
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(s[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c",pop());
    }
    cout<<"\nMathematical Result: "<<getValue(new_str)<<endl;;
}





int main()
{
    /* Main Program */
    int choice;
//printf("Press 1 to continue\n");
    printf("****Conversion from Infix to Postfix and Prefix****\n\n");
    printf("Main Menu:\n\n");
    printf("\t1.Infix to Postfix\n");
    printf("\t2.Infix to Prefix\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        infix_to_postfix();

        break;
    case 2:
        infix_to_prefix();

        break;
    case 0:
        break;
    }
    main();

}

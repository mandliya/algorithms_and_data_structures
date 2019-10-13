bool areParanthesisBalanced(string expr)
{
    stack s;
    char x;


    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {

            s.push(expr[i]);
            continue;
        }

        if (s.empty())
           return false;

        switch (expr[i])
        {
        case ')':

            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':


            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':

            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }


    return (s.empty());
}

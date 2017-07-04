char *strtok_safe_newline(char *text, char **save_this)
{
    if (text != NULL)
    {
        /* New text. */
        int i = 0;
        while(text[i] != '\0') 
        {
            if(text[i] == '\n')
            {
                text[i] = '\0';
                *save_this = &text[i + 1];
                return text;
            }
            i++;
        }
    }
    else if ((save_this != NULL) && (*save_this != NULL))
    {
        /* Old text. */
        int i = 0;
        char *start = *save_this;
        while((*save_this)[i] != '\0')
        {
            if((*save_this)[i] == '\n')
            {
                (*save_this)[i] = '\0';
                *save_this = &((*save_this)[i + 1]);
                return start;
            }
            i++;
        }
        *save_this = NULL;
        save_this = NULL;
        return start;
    }
    return NULL;
}
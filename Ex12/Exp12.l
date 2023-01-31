	int num_words = 0,num_lines = 0, num_chars = 0;
	
%%
[:space:]	++num_words; ++num_chars;
\n			++num_lines;
.      		++num_chars;
%%

	int main()
             {
		         yyin = fopen("input.c", "r" );
		         yylex();
		         printf( "# of lines = %d\n# of words = %d\n# of chars = %d\n",num_lines,num_words,num_chars );
             }

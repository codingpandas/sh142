//
//  parser.h
//  sh142
//
//  Created by Alben Cheung on 11/24/12.
//  Copyright (c) 2012 Alben Cheung. All rights reserved.
//

#ifndef sh142_parser_h
#define sh142_parser_h

void parse_args(char *buffer, char** args,
                size_t args_size, size_t *nargs)
{
    char *buf_args[args_size]; /* You need C99 */
    char **cp;
    char *wbuf;
    size_t i, j;
    
    wbuf=buffer;
    buf_args[0]=buffer;
    args[0] =buffer;
    
	
	
    for(cp=buf_args; (*cp=strsep(&wbuf, " \n\t")) != NULL ;){	//separates the commands/args
        if ((*cp != '\0') && (++cp >= &buf_args[args_size]))	//cp growing past limit of buf_args, break
            break;
    }
    
    for (j=i=0; buf_args[i]!=NULL; i++){
        if(strlen(buf_args[i])>0)
            args[j++]=buf_args[i];
    }
    
    *nargs=j;
    args[j]=NULL;
}

void for_analyze(char *buffer, char** cmds, size_t  args_size, size_t &ncmds )
{
	char *result;
	char *sampler;
	char **output;
	char *buf_args[args_size];
	int iterations = 1;
	size_t i, j;
	
	output = buf_args;
	*sampler = *buffer;
	result = strsep(&sampler, "(");
	cout <<result;
	if(result == "for")
	{	//req garbage collections
		strsep(&sampler, "<");
		result = strsep(&sampler, ";");
		iterations = atoi(result);
		strsep(&sampler, ")");
		
		for(i = 0;(result != "forend");i++){		//parses through until end of for loop
			output [i] = result;
			result = strtok(NULL, ";");
		}
		
		for ( j = i = 0; output[i] != NULL ; i++ ){
        if ( strlen ( output[i] ) > 0 )
            cmds[j++] = output[i];
		}
		cmds[j] = NULL;
		ncmds = j;
		
		for ( i = 1 ; i < iterations ; i++)
		{
			for( j = 0; j < ncmds; j++)
			{
				cmds[ (i * ncmds) + j ] = cmds[ j ];
			}
		}
		cmds [ (ncmds = (j + 1) * iterations) ] = NULL;
		
		i = 0;
		while( cmds[i] )
		{
			cout << cmds[i] << endl;
		}
			
    }
	else
	{
		
	}
	delete []sampler;
	
}


#endif

#include "ini_parser.h"
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

namespace qh
{
	char *GetIniKeyString(char *title,char *key,char *filename)
	{
    FILE *fp;
    char szLine[1024];
    static char tmpstr[1024];
    int rtnval;
    int i = 0;
    int flag = 0;
    char *tmp;

    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("have   no   such   file \n");
        return "";
    }
    while(!feof(fp))
    {
        rtnval = fgetc(fp);
        if(rtnval == EOF)
        {
            break;
        }
        else
        {
            szLine[i++] = rtnval;
        }
        if(rtnval == '\n')
        {
#ifndef WIN32
            //i--;
#endif
            szLine[--i] = '\0';
            i = 0;
            tmp = strchr(szLine, '=');

            if(( tmp != NULL )&&(flag == 1))
            {
                if(strstr(szLine,key)!=NULL)
                {
                    //注释行
                    if ('#' == szLine[0])
                    {
                    }
                    else if ( '\/' == szLine[0] && '\/' == szLine[1] )
                    {

                    }
                    else
                    {
                        //找打key对应变量
                        strcpy(tmpstr,tmp+1);
                        fclose(fp);
                        return tmpstr;
                    }
                }
            }
            else
            {
                strcpy(tmpstr,"[");
                strcat(tmpstr,title);
                strcat(tmpstr,"]");
                if( strncmp(tmpstr,szLine,strlen(tmpstr)) == 0 )
                {
                    //找到title
                    flag = 1;
                }
            }
        }
    }
    fclose(fp);
    return "";
}

    INIParser::INIParser(){

    }

    INIParser::~INIParser(){

    }

    bool INIParser::Parse(const std::string& ini_file_path)
    {
    	char* file_path;
    	strcpy(file_path,  ini_file_path.c_str());

    	char data1[32];
    	strcpy(data1, GetIniKeyString("config","ini_data",file_path));
    	char * ini_data = data1;

    	char data2[32];
    	strcpy(data2, GetIniKeyString("config","line_seperator",file_path));
    	char * line_seperator = data2;

    	char data3[32];
    	strcpy(data3, GetIniKeyString("config","key_value_seperator",file_path));
    	char * key_value_seperator = data3;

    	return Parse(ini_data, strlen(ini_data), line_seperator, key_value_seperator);
    }

    bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
    {
        vector<string > str_line;
        string str_data = ini_data;
        int i = 0;
        string str = "";
        while (str_data.size() != 0)
        {
            size_t pos = str_data.find(line_seperator);
            if (pos != string::npos)
            {
                string str = str_data.substr(0, pos);
                str_data = str_data.substr(pos + line_seperator.size(), str_data.size() - 1);
                str_line.push_back(str);
            }
            else
            {
                str_line.push_back(str_data);
                str_data = "";
            }
        }

        for (int i = 0; i < str_line.size(); i++)
        {
            string a_str = str_line[i];
            int pos = a_str.find(key_value_seperator);
            string lmap = a_str.substr(0, pos);
            string rmap = a_str.substr(pos + 1, a_str.size() - 1);
            key_value[lmap] = rmap;
        }

        return 1;
    }

    const std::string& INIParser::Get(const std::string& key, bool* found)
    {
        string value = key_value[key];
        if (value != "")
            found = new bool(1);
        else
            found = new bool(0);

        return key_value[key];
    }

    const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
    {
        string str_data = section;
        bool key_find = false;
        while (str_data.size() != 0)
        {
            size_t pos = str_data.find(',');
            if (pos != string::npos)
            {
                string str = str_data.substr(0, pos);
                str_data = str_data.substr(pos + 1, str_data.size() - 1);
                if (key == str)
                {
                    key_find = true;
                    break;
                }
            }
            else
            {
                if (str_data == key)
                {
                    key_find = true;
                }
                str_data = "";
            }
        }
        if (key_find)
            return Get(key, found);
        else
            return NULL;
    }
}


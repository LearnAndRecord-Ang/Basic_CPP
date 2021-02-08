// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// //字符串分割函数
// std::vector<std::string> split(std::string str,std::string pattern)
// {
//     std::string::size_type pos;
//     // std::vector<std::string> result;
//     std::string result;
//     str+=pattern;//扩展字符串以方便操作
//     int size=str.size();

//     for(int i=0; i<size; i++)
//     {
//         pos=str.find(pattern,i);
//         if(pos<size)
//         {
//             std::string s=str.substr(i,pos-i)+'.';
//             result.push_back(s);
//             i=pos+pattern.size()-1;
//         }
//     }
//     return result;
// }

// int main()
// {
//     std::string str;
//     // std::cout<<"Please input str:"<<std::endl;
//     //std::cin>>str;
//     str = "192:168:1:1";
//     std::string pattern;
//     // std::cout<<"Please input pattern:"<<std::endl;
//     //std::cin>>pattern;
//     pattern = ":";
//     // getline(std::cin,pattern);//用于获取含空格的字符串
//     std::vector<std::string> result=split(str,pattern);

//     std::cout<<"The result:"<<std::endl;
//     for(int i=0; i<result.size(); i++)
//     {
//         std::cout<<result[i]<<std::endl;
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
*
* @author: cnscn@163.com
* @reference: lovesnow1314@http://community.csdn.net/Expert/TopicView3.asp?id=5198221 
*
* 用新子串newstr替换源字符串src中的前len个字符内所包含的oldstr子串
*
* @param char* dest 目标串，也就是替换后的新串
* @param const char* src 源字符串，被替换的字符串
* @param const char* oldstr 旧的子串，将被替换的子串
* @param const char* newstr 新的子串
* @param int len 将要被替换的前len个字符
*
* @return char* dest 返回新串的地址
*
*/
char *strreplace(char *dest, char *src, const char *oldstr, const char *newstr, size_t len)
{
    //如果串相等，则直接返回
    if(strcmp(oldstr, newstr)==0)
    return src;
    
    //子串位置指针
    char *needle;
    
    //临时内存区
    char *tmp;
    
    //把源串地址赋给指针dest，即让dest和src都指向src的内存区域
    dest = src;
    
    //如果找到子串, 并且子串位置在前len个子串范围内, 则进行替换, 否则直接返回
    while((needle = strstr(dest, oldstr)) && (needle -dest <= len))
    {
        //分配新的空间: +1 是为了添加串尾的'\0'结束符
        tmp=(char*)malloc(strlen(dest)+(strlen(newstr)-strlen(oldstr))+1);
        
        //把src内的前needle-dest个内存空间的数据，拷贝到arr
        strncpy(tmp, dest, needle-dest);
        
        //标识串结束
        tmp[needle-dest]='\0';
        
        //连接arr和newstr, 即把newstr附在arr尾部, 从而组成新串(或说字符数组)arr
        strcat(tmp, newstr);
        
        //把src中 从oldstr子串位置后的部分和arr连接在一起，组成新串arr
        strcat(tmp, needle+strlen(oldstr));
        
        //把用malloc分配的内存，复制给指针retv
        dest = strdup(tmp);
        
        //释放malloc分配的内存空间
        free(tmp);
    }
    
    return dest;
}
 
int main()
{
    char *str="192：168：1：1";
    char *old="：";
    char *test=".";
    
    char *dest;
    //分配内存空间: 大小 == src的长度 ＋ newstr和oldstr长度差(可能是正负或0)+1
    // printf("%s\n",strreplace(dest, str, old, test,1));
    // printf("%s\n",strreplace(dest, str, old, test,5));
    printf("%s\n",strreplace(dest, str, old, test,40));
    return 0;
}
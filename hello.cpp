#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

void readAndwrite(){    
    int total = 0;
    FILE *f;
    f = fopen("pseudo_session.txt", "ab+");
    if(!f) {
    	cout << "something went wrong" << endl;
        perror("File opening failed");
    }
    else{
        fscanf(f,"%d",&total);
        fclose(f);
        cout << "<br/>\n";
        printf("Общее количество посещений: %d\n", total);
        ++total;
        f = fopen("pseudo_session.txt","wb+");
        fprintf(f ,"%d", total);
        fclose(f);
    }
}

int main () {
   string user_cookie;
   string request_method;
   string request_data;
   int size = 4;
   int keys[size] = { 3,1,2,1 };
   int answers[size];
   int rightAnswersCounter = 0;


   if(getenv("HTTP_COOKIE")) {
   		user_cookie = getenv("HTTP_COOKIE");	
   		user_cookie = user_cookie.substr(12);
   	    cout << "Set-Cookie:UserCounter=" <<  atoi(user_cookie.c_str()) + 1 << ";\r\n";					
   } else {
		cout << "Set-Cookie:UserCounter=0;\r\n";
   }
	
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Cookies in CGI</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   
   request_method = getenv("REQUEST_METHOD");

   if(request_method == "POST") {
		cin >> request_data;
   } else {
   		request_data = getenv("QUERY_STRING");
   }

   for(int i = 0; i < size; i++) {
		answers[i] = atoi(request_data.substr(request_data.find("=") + 1, 1).c_str()); 
		request_data = request_data.substr(request_data.find("=") + 1);
   }

   for(int i = 0; i < size; i++) {
   		if(answers[i] == keys[i]) {
   			rightAnswersCounter++;
   		}
   }

   cout << "Правильных ответов: " << rightAnswersCounter 
   		<< " из " << size  << endl;

   cout << "<br/>\n";
   cout << "Количество попыток: " << user_cookie << endl;

   readAndwrite();

   cout << "<br/>\n";
   cout << "</body>\n";
   cout << "</html>\n";
   
   return 0;
}
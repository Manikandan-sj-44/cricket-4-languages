#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 9003
#define BUFFER_SIZE 8192

char* generate_html() {
    time_t now;
    time(&now);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp)-1] = '\0';
    
    char* html = malloc(BUFFER_SIZE);
    if (!html) return NULL;
    
    sprintf(html,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "    <title>🏏 Cricket Scores - C</title>\n"
        "    <style>\n"
        "        * { margin: 0; padding: 0; box-sizing: border-box; }\n"
        "        body {\n"
        "            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n"
        "            background: linear-gradient(135deg, #1a472a 0%%, #0e2a1a 100%%);\n"
        "            min-height: 100vh;\n"
        "            padding: 20px;\n"
        "        }\n"
        "        .container { max-width: 1200px; margin: 0 auto; }\n"
        "        h1 { text-align: center; color: #ffd700; margin-bottom: 20px; font-size: 3em; }\n"
        "        .lang-badge {\n"
        "            text-align: center;\n"
        "            background: #ffd700;\n"
        "            color: #1a472a;\n"
        "            display: inline-block;\n"
        "            padding: 5px 20px;\n"
        "            border-radius: 20px;\n"
        "            margin-bottom: 20px;\n"
        "            font-weight: bold;\n"
        "        }\n"
        "        .matches-grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); gap: 20px; }\n"
        "        .match-card {\n"
        "            background: white;\n"
        "            border-radius: 15px;\n"
        "            padding: 20px;\n"
        "            box-shadow: 0 10px 20px rgba(0,0,0,0.2);\n"
        "        }\n"
        "        .teams { display: flex; justify-content: space-between; align-items: center; margin-bottom: 15px; }\n"
        "        .team { text-align: center; flex: 1; }\n"
        "        .team-name { font-size: 1.3em; color: #1a472a; font-weight: bold; }\n"
        "        .team-score { font-size: 1.5em; font-weight: bold; color: #333; }\n"
        "        .vs { font-size: 1.2em; color: #ff6600; padding: 0 15px; }\n"
        "        .status { background: #ffd700; padding: 8px; border-radius: 8px; text-align: center; font-weight: bold; }\n"
        "        .result { background: #1a472a; color: #ffd700; padding: 8px; border-radius: 8px; text-align: center; font-weight: bold; }\n"
        "        .overs { text-align: center; color: #666; margin-top: 10px; }\n"
        "        .footer { text-align: center; color: #ccc; margin-top: 30px; padding: 20px; }\n"
        "        .time { font-size: 0.8em; margin-top: 10px; }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class=\"container\">\n"
        "        <div style=\"text-align: center;\">\n"
        "            <div class=\"lang-badge\">🖥️ C HTTP SERVER</div>\n"
        "        </div>\n"
        "        <h1>🏏 LIVE CRICKET SCORES</h1>\n"
        "        <div class=\"matches-grid\">\n"
        "            <div class=\"match-card\">\n"
        "                <div class=\"teams\">\n"
        "                    <div class=\"team\"><div class=\"team-name\">India</div><div class=\"team-score\">245/3</div></div>\n"
        "                    <div class=\"vs\">VS</div>\n"
        "                    <div class=\"team\"><div class=\"team-name\">Australia</div><div class=\"team-score\">210/5</div></div>\n"
        "                </div>\n"
        "                <div class=\"status\">⚡ India needs 35 runs in 88 balls</div>\n"
        "                <div class=\"overs\">Overs: 35.2</div>\n"
        "            </div>\n"
        "            <div class=\"match-card\">\n"
        "                <div class=\"teams\">\n"
        "                    <div class=\"team\"><div class=\"team-name\">England</div><div class=\"team-score\">189/7</div></div>\n"
        "                    <div class=\"vs\">VS</div>\n"
        "                    <div class=\"team\"><div class=\"team-name\">South Africa</div><div class=\"team-score\">156/4</div></div>\n"
        "                </div>\n"
        "                <div class=\"status\">⚡ England leads by 33 runs</div>\n"
        "                <div class=\"overs\">Overs: 28.1</div>\n"
        "            </div>\n"
        "            <div class=\"match-card\">\n"
        "                <div class=\"teams\">\n"
        "                    <div class=\"team\"><div class=\"team-name\">Pakistan</div><div class=\"team-score\">312/4</div></div>\n"
        "                    <div class=\"vs\">VS</div>\n"
        "                    <div class=\"team\"><div class=\"team-name\">New Zealand</div><div class=\"team-score\">278/6</div></div>\n"
        "                </div>\n"
        "                <div class=\"result\">🏆 Pakistan won by 34 runs</div>\n"
        "                <div class=\"overs\">Overs: 50.0</div>\n"
        "            </div>\n"
        "            <div class=\"match-card\">\n"
        "                <div class=\"teams\">\n"
        "                    <div class=\"team\"><div class=\"team-name\">Sri Lanka</div><div class=\"team-score\">168/2</div></div>\n"
        "                    <div class=\"vs\">VS</div>\n"
        "                    <div class=\"team\"><div class=\"team-name\">Bangladesh</div><div class=\"team-score\">145/3</div></div>\n"
        "                </div>\n"
        "                <div class=\"status\">⚡ Sri Lanka needs 23 runs</div>\n"
        "                <div class=\"overs\">Overs: 32.4</div>\n"
        "            </div>\n"
        "        </div>\n"
        "        <div class=\"footer\">\n"
        "            <p>Language: <strong>C</strong> | Framework: Raw HTTP | Internal Port: 9003</p>\n"
        "            <p>Accessed via: <strong>/c</strong> path on proxy</p>\n"
        "            <div class=\"time\">%s</div>\n"
        "        </div>\n"
        "    </div>\n"
        "</body>\n"
        "</html>\n",
        timestamp);
    return html;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);
    
    printf("C Server running on port %d\n", PORT);
    
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);
        
        char* response = generate_html();
        send(new_socket, response, strlen(response), 0);
        free(response);
        close(new_socket);
    }
    return 0;
}

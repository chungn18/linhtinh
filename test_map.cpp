#include <unordered_map>
#include <iostream>
#include <openssl/ssl.h>

void clearMapCTX(std::unordered_map <SSL_CTX*, int> mapctx){
    for(auto it = mapctx.begin(); it != mapctx.end(); it++){
        if(it->first ==NULL){
            mapctx.erase(it);
        }
    }
}

void printMap(std::unordered_map <SSL_CTX*, int> mapctx){
    for (auto it = mapctx.begin(); it != mapctx.end(); it++){
        int i = 1;
        std::cout << "mapCTX[" << i <<"]" << " First: " << it->first << ", Second: " << it->second << std::endl;
        i++;
    }
}

int main() {
    SSL_CTX * ctx1 = SSL_CTX_new(SSLv23_method());
    SSL_CTX * ctx2 = SSL_CTX_new(SSLv23_method());
    SSL_CTX * ctx3 = SSL_CTX_new(SSLv23_method());

    std::unordered_map <SSL_CTX*, int> mapCTX;
    mapCTX[ctx1] = 1;
    mapCTX[ctx2] = 2;
    mapCTX[ctx3] = 3;

    std::cout << "Show values of mapCTX before SSL_CTX null\n";  
    printMap(mapCTX);
    SSL_CTX_free(ctx2);
    std::cout << "Show values of mapCTX after SSL_CTX null\n";
    clearMapCTX(mapCTX);
    printMap(mapCTX);




}


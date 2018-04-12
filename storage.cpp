#include <storage.h>

std::ofstream make_file_stream() {
    std::ofstream os;
    os.open ("./utxo.bin", std::ofstream::binary);
    return os;
}


UTXO recover(std::ifstream &is, size_t offset) {

    UTXO *out = new UTXO();

    is.seekg(offset);
    is.read(reinterpret_cast<char*>(out), SIZEUTXO);

    return *out;
}


void UTXO::write(std::ofstream &os) {
	os.write(reinterpret_cast<char*>(this), SIZEUTXO);
};


//std::string crypto(const std::string& data, const std::string& key) {
//
//	std::string coded = data;
//
//	for (int i = 0; i < coded.length(); i++)
//	      coded[i] = data[i] ^ key[i % key.length()];
//
//	return coded;
//}
//
//std::string make_key() {
//
//  srand (time(NULL));
//  int intKey = rand();
//
//  char* ptr_key = static_cast<char*>(static_cast<void*>(&intKey));
//
//  char key[sizeof(intKey)];
//  std::copy(ptr_key, ptr_key + sizeof(intKey), key);
//
//  return std::string(key);
//}

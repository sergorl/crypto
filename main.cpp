#include <iostream>
#include <secp256k1.h>
#include <ecc.h>
#include <storage.h>

int main()
{
//    ECC::Hash hash1;
//
//    std::cout << "Context is inint." << std::endl;
//    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
//
//    secp256k1_pubkey pkey;
//    const unsigned char skey[32] = "abc_123\0";
//
//    std::cout << sizeof(skey) << std::endl;
//
////    if (secp256k1_ec_pubkey_create(ctx, &pkey, skey)) cout << "Pub key is done.\n";
////    else cout << "Invalid secret key is found!\n";
//
//    secp256k1_context_destroy(ctx);
//    std::cout << "Context is destroyed." << std::endl;


    // Write UTXO to file

    std::ofstream os = make_file_stream();

    UTXO u1(1, "abc");
    UTXO u2(22, "123");
    UTXO u3(333, "_qwerty_");

    u1.write(os);
    u2.write(os);
    u3.write(os);

    os.close();

    // Recovering from file

    std::ifstream is("./utxo.bin", std::ios::binary);
    UTXO out_recover = recover(is, 2*SIZEUTXO);
//
    std::cout << "id = " << out_recover.id << "; str = " << out_recover.str;

    is.close();

    return 0;
}


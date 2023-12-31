#include <iostream> 

#include "Encoder.h"
#include "Decoder.h"

using namespace std;

void welcome_message()
{
    cout << "  _    _   _    _   ______   ______   _____    _____     ____        __  __   ______ " << "\n";
    cout << " | |  | | | |  | | |  ____| |  ____| |  __ \\  |  __  \\  / __ \\      |  \\/  | |  ____|" << "\n";
    cout << " | |__| | | |  | | | |__    | |__    | |__) | | |__) | | |  | |     | \\  / | | |__   " << "\n";
    cout << " |  __  | | |  | | |  __|   |  __|   |  ___/  |  _  /  | |  | |     | |\\/| | |  __|  " << "\n";
    cout << " | |  | | | |__| | | |      | |      | |      | |\\ \\   | |__| |  _  | |  | | | |____ " << "\n";
    cout << " |_|  |_| \\_____/  |_|      |_|      |_|      |_| \\_\\  \\_____/  (_) |_|  |_| |______|" << "\n";
    cout << "                                                                                     " << "\n";

    cout << "-------------------------------------------------------------------------------------" << "\n";
    cout << "Welcome! To start, please select the option of your desire:" << "\n";
}

void handle_compress_file()
{
    cout << "[RUN]: To compress a file, provide the full path to that file. Example: C:\\Downloads\\MyFolder\\myfile.txt\n";
    cout << "[RUN]: File Path: ";
    char path_to_file[150];
    cin >> path_to_file;

    cout << "\n[RUN]: Now, provide the path to the folder where the file must be discharged, as well as the name of the compressed file. Example: C:\\Downloads\\MyOtherFolder\\compressed.me\n";
    cout << "[RUN]: Folder Path: ";
    char output_folder_path[150];
    cin >> output_folder_path;

    Encoder::encode(path_to_file, output_folder_path);

    cout << "\n\n[INFO]: Success! The file was successfully compressed!\n";
}

void handle_unzip_file()
{
    cout << "[RUN]: To unzip a file, provide the full path to the compressed file with .me extension. Example: C:\\Downloads\\MyFolder\\compressedfile.me\n";
    cout << "[RUN]: File Path: ";
    char path_to_file[150];
    cin >> path_to_file;

    cout << "\n[RUN]: Now, provide the path to the folder where the file must be discharged, as well as the name of the unzipped file. Example: C:\\Downloads\\MyOtherFolder\\unzziped.txt\n";
    cout << "[RUN]: Folder Path: ";
    char output_folder_path[150];
    cin >> output_folder_path;

    Decoder::decode(path_to_file, output_folder_path);

    cout << "\n\n[INFO]: Success! The file was successfully unzipped!\n";
}

int main()
{
    welcome_message();

    unsigned char selected_option;
    do {
        cout << "\n------------------------------------------------------\n";
        cout << "1 - COMPRESS a file.\n";
        cout << "2 - UNZIP a compressed file.\n";
        cout << "3 - CLOSE the program.\n";
        cout << "------------------------------------------------------\n";

        cout << "Option: ";
        cin >> selected_option;
        cout << "------------------------------------------------------\n";

        switch (selected_option)
        {
        case '1':
            handle_compress_file();
            break;

        case '2':
            handle_unzip_file();
            break;

        case '3':
            cout << "[INFO]: Closing program...\n";
            break;

        default:
            cout << "[ERROR]: Sorry, that is not a valid option!\n";
            break;
        }
    } while (selected_option != '3');

    return 0;
}

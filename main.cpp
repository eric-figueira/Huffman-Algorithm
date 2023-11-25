#include <iostream> 

#include "Encoder.h"
#include "Decoder.h"

using namespace std; 

void welcome_message() 
{
  cout << "  _    _   _    _   ______   ______   _____    _____     ____        __  __   ______ " << "\n";
  cout << " | |  | | | |  | | |  ____| |  ____| |  __ \  |  __ \   / __ \      |  \/  | |  ____|" << "\n";
  cout << " | |__| | | |  | | | |__    | |__    | |__) | | |__) | | |  | |     | \  / | | |__   " << "\n";
  cout << " |  __  | | |  | | |  __|   |  __|   |  ___/  |  _  /  | |  | |     | |\/| | |  __|  " << "\n";
  cout << " | |  | | | |__| | | |      | |      | |      | | \ \  | |__| |  _  | |  | | | |____ " << "\n";
  cout << " |_|  |_|  \____/  |_|      |_|      |_|      |_|  \_\  \____/  (_) |_|  |_| |______|" << "\n";
  cout << "                                                                                     " << "\n";

  cout << "-------------------------------------------------------------------------------------" << "\n";
  cout << "Welcome! To start, please select the option of your desire";
}

void welcome_message_correct() 
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
  cout << "To compress a file, provide the full path to that file. Example: C:\\Downloads\\MyFolder\\myfile.txt\n";
  cout << "File Path: ";
  char path_to_file[150];
  cin >> path_to_file;

  cout << "Now, provide the path to the folder where the file must be discharged. Example: C:\\Downloads\\MyOtherFolder\n";
  cout << "Folder Path: ";
  char output_folder_path[150];
  cin >> output_folder_path;

  cout << path_to_file;
  cout << output_folder_path;

  Encoder encoder(path_to_file);
  encoder.encode(output_folder_path);

  cout << "\n" << "Success! The file was successfully compressed!";
}

void handle_unzip_file()
{
  cout << "To unzip a file, provide the full path to the compress file. Example: C:\\Downloads\\MyFolder\\myfile.txt.me\n";
}

int main()
{
    welcome_message_correct();

    cout << "1 - COMPRESS a file." << "\n";
    cout << "2 - UNZIP a compressed file." << "\n";
    cout << "--------------------------------" << "\n";
    cout << "Option: ";

    unsigned char selected_option;
    cin >> selected_option;
    cout << "--------------------------------" << "\n";

    switch (selected_option)
    {
      case '1':
        handle_compress_file();
        break;

      case '2':
        break;
      
      default:
        cout << "[ERROR]: Sorry, that is not a valid option!";
        break;
    }

    return 0;
}

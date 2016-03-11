/*
-David Ribeiro

C++ HTML interpeter!

For the purposes of continuity when talking about this project, the characters like '@', '#' that are used to manipulate
the html tags can be called glyphs. 

Things to Add here

- Support for tons more html tags
- Perhaps having \n and end lines be able to close certain tags without having to explicitly close them with a matching glyph
- Maybe a better system for capturing Char's for output
- Have the program output to an html file.
- Maybe have a dedicated Styling section with its own open and close glyphs so users can add their own styling inline!

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
        fstream data ("input.txt" , ios::in); // open the file for reading
        char c; // For the current character in the text file
        bool capture = 0; //Whether or not to send char to the stream
        bool subcap = 0;
    
    // If the file opening was successful
    if (data.is_open())
    {
        // While there are still characters to read
        while ( data.get(c))
        {
            
            
            switch (c) {
                    
                case '#':// Header Operator
                    if (capture == 1)
                    {
                        cout << "</h1>" << endl;
                        capture = 0;
                    }
                    else if (capture == 0)
                    {
                        cout << "<h1>";
                        capture = 1;
                    }
                    continue;
                    break;
                    
                case '@': // Paragraph Operator
                    if (capture == 1)
                    {
                        cout << "</p>" << endl;
                        capture = 0;
                    }
                    else if (capture == 0)
                    {
                        cout << "<p>";
                        capture = 1;
                    }
                    continue;
                    break;
                    
                case '!':
                    cout << "<br>" << endl;
                    break;
                    
                case '_':
                    if (subcap == 1)
                    {
                        cout << "</sub>" << endl;
                        subcap = 0;
                    }
                    else if (subcap == 0)
                    {
                        cout << "<sub>";
                        subcap = 1;
                    }
                    continue;
                default:
                    break;
            }

            
            // Read out the letter if capture is true.
            if (capture == 1 || subcap == 1)
            {
                cout << c ;
            }
            
        
        
        }
       
        data.close(); // Close the file 
    }

}

    
    
    


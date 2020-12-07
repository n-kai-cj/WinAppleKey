/*
   Copyright 2020 .

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#define WIN32_LEAN_AND_MEAN // To reduce the size off the Win32 header files
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

    DWORD dwSleepTime = 5000;
    if (argc == 2)
    {
        dwSleepTime = std::stoi(argv[1]);
    }
    printf("%u[ms] sleep ... ", dwSleepTime);
    Sleep(dwSleepTime);

    POINT last_pos;
    while (true)
    {

        POINT pos;
        bool ret = GetCursorPos(&pos);
        if (ret)
        {
            printf("mouse ret=%d, %d, %d\n", ret, pos.x, pos.y);
            if (std::abs(last_pos.x - pos.x) < 2 &&
                std::abs(last_pos.y - pos.y) < 2)
            {
                ret = SetCursorPos(pos.x + 1, pos.y);
                if (!ret)
                {
                    SetCursorPos(pos.x - 1, pos.y);
                }
            }
            last_pos = pos;
        }

        printf("%u[ms] sleep ... ", dwSleepTime);
        Sleep(dwSleepTime);
    }

    return 0;
}

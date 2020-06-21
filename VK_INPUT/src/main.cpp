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

int main(int argc, char* argv[]) {

    DWORD dwSleepTime = 5000;
    printf("%u[ms] sleep ... ", dwSleepTime);
    Sleep(dwSleepTime);

    while (true) {

        BYTE VK = VK_NONAME;

        printf("%d press\t", VK);
        keybd_event(VK, 0, 0, 0);
        keybd_event(VK, 0, KEYEVENTF_KEYUP, 0);

        printf("%u[ms] sleep ... ", dwSleepTime);
        Sleep(dwSleepTime);
    }

    return 0;
}


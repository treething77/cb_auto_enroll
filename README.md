# cb_auto_enroll
Arduino script for automated Chromebook enrollment

This script can be uploaded to any Arduino board with a USB connection and then connected to a Chromebook to automatically enroll it.

Some things to note:

1. The script will require changes for the correct wifi name, password, etc.
2. The script needs to run on a fresh Chromebook, literally just open it up and plug in the Arduino device. 
3. The script takes about 30 seconds to run in total. 

The script was based on a RubberDucky script (https://www.youtube.com/watch?v=VqbYysRtkxw). It was run through a modified version of Duckuino, with modifications to adjust timings etc. Some additional code was added to set the prescaler in an attempt to reduce some randomness in the behavior of the program. The Duckuino modifications could be available on request. I did try making a pull request to that repo but it seemed to be blocked.

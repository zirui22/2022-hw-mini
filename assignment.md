# Miniproject assignment

The assignment is similar to a task an engineer using embedded systems often faces--taking an example program, modifying it to fit a need, and measuring the results.
This assignment uses the Raspberry Pi Pico (non-W no wireless version) as handed out in class.
The Pico W accesses the on-board LED using a different API and I haven't tested that to see if it works, so we use the **plain non-wireless Pico**.

In this Git repository, the directory [src/pwm/led_fade](./src/pwm/led_fade) contains C source code for a program that constantly loops LED intensity from zero to high to zero again with a relatively smooth change.

## Summary

This assignment has the student measure the original pwm/led_fade program's LED intensity vs. time, modify the pwd/led_fade source code, compile the modified code, upload the .uf2 binary to the Pico and then measure the results with a video camera such as is typical on smartphones.

This assignment is generally done in teams of two students. Each student has a Pico so you don't physically have to be in the same place to do the work.
Although you can work in your own Git repos, please decide on a single Git repo to have as your final assignment submitted.

## Rubric

Score out of 10 points total:

* 3 points: get Pico working to run LED pwm/led_fade original example
* 5 points: modify pwm/led_fade example and upload measurements to allow comparing original program vs. your modified program
* 2 points: brief report (1-2 paragraphs + measurements) uploaded to your Github repo as Report.md (markdown text file)

Note: GitHub and Git are not meant for files more than several megabytes. So don't make the videos too big/long. FFmpeg or most other video editors can help you trim the video size and length if desired.

## Process

1. Fork this repository with your GitHub username (each student)
2. Setup the 32-bit ARM GCC compiler if you don't already have it, as in [compiler.md](./doc/compiler.md)
3. from your laptop/desktop, build the original pwm/led_fade example
4. copy the pwm_led_fade.ufs to the Pico as described in [upload.md](./doc/upload.md)
5. take a video of the LED fading up and down a couple times with your phone or whatever camera you wish. Please keep the video less than about 5 seconds long to save file size.
6. Modify the pwm/led_fade example as you like to make your own fading/changing LED pattern. Something non-trivial please (i.e. not always on or always off or invisible to the human or video camera).
7. take a video of your program's LED changing.
8. Make a brief report explaining your code changes and the effect you desired, and how successful you felt you were at it.

Thank you!

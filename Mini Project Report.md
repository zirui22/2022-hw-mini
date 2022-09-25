Hardware Team 1: Mini Project Report
        
        After installing the necessary softwares and compilers, we successfully uploaded the code onto our raspberry pi. We observed the LED light on the Raspberry pi lighting up brighter and brighter, and after reaching a certain brightness, the LED light starts to get dimmer and dimmer. Being completely dimmed, the LED light would repeat the process again. Looking through the code, we know this is achieved by the interrupt handler function on_pwm_wrap() and the clock counter inside the main function. 
        
        The non-trivial change we decided to do is, instead of making the LED light to light up and turn off, we wanted it to light the Morse code pattern of “SOS”. To achieve this, we rewrote the code inside the on_pwm_wrap() function. The remodeled function would read in a string representing the Morse code of “SOS” when it is called each time, then depending on if it is reading in a ‘.’ or ‘-” the LED light would be set to light up for a different length of time. 




Here is the link for demonstration video:
https://drive.google.com/file/d/175v16ttpDTj-ooaXVi95P3kynclF5kdM/view?usp=sharing

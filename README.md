# Q Peek

Creates a small always-on-top window that shows a live thumbnail preview of an application window whenever it is not focused. I use it to keep an eye on games while doing other things. 

 - eo_q_peek.exe <Application name>
 
## Features

- Automatically detects when an application loses focus
- Displays a 320×180 pixel live preview in the bottom right of the screen
- Uses Windows DWM thumbnail APIs for real-time rendering
- Disappears when the application regains focus
- Clean, non-intrusive overlay with no focus stealing


- Application must be in windowed or borderless fullscreen mode, not exclusive fullscreen
Note: This ReadMe was originally for graders of an assignment within this course, but the same steps can be followed to see the engine working.
Additionally, this is an older version of the engine, and I plan to make the final/current engine public once I am done cleaning it.

INSTRUCTIONS:
	
	SEGMENT/CIRCLE/TRIANGLE, GEOMETRY SHOWCASE:
		1. Set PLAY_PONG and PLAY_NAME_SCROLL in scene.h to false.
		2. Set SHOW_GEOMETRY in scene.h to true.
		3. Start application. 

	SCROLLING NAME:
		1. Set PLAY_PONG and SHOW_GEOMETRY in scene.h to false.
		2. Set PLAY_NAME_SCROLL in scene.h to true.
		3. Start application.
		3. Click "Play" button.

	TIFF FILES:
		1. Set TIFF_FILE_IN and TIFF_FILE_OUT in scene.h.
		2. Start application.
		3. Click buttons as needed (refer to BUTTONS section)

	EXTRA CREDIT - PONG:
		1. Set PLAY_NAME_SCROLL and SHOW_GEOMETRY in scene.h to false.
		1. Set PLAY_PONG in scene.h to true.
		2. Start application. 
		3. Click "Play" button.
		4. Press left/right keys to control bottom player.
		5. Press top/bottom keys to control top player.
		6. Check the terminal for the current score.

BUTTONS:

	Click "Load Tiff" to load the tiff file specified by TIFF_FILE_IN in scene.h
	Click "Save Tiff" to save the framebuffer to the file specified by TIFF_FILE_OUT in scene.h
	Click "Play" to start animations for Pong + Name.

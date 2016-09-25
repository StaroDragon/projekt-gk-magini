#include "Controls.h"
#include <stdio.h>

void Keyboard::KeyDown(unsigned char key)
{
	keyState[key] = BUTTON_DOWN;
}
void Keyboard::KeyUp(unsigned char key)
{
	keyState[key] = BUTTON_UP;
}

void Keyboard::ProcessKeyboard()
{
	if (keyState[(unsigned char)'w'])
		m_camera->MoveCamera(CAMERA_UP, 0.05f);	
	if (keyState[(unsigned char)'s'])
		m_camera->MoveCamera(CAMERA_DOWN, 0.05f);
	if (keyState[(unsigned char)'a'])
		m_camera->MoveCamera(CAMERA_LEFT, 0.05f);
	if (keyState[(unsigned char)'d'])
		m_camera->MoveCamera(CAMERA_RIGHT, 0.05f);
}

void Keyboard::ProcessKeyboard(Player *player)
{
	if (keyState[(unsigned char)'w'])
		player->Jump();
	if (keyState[(unsigned char)'a'])
		player->MoveLeft();
	if (keyState[(unsigned char)'d'])
		player->MoveRight();

	if (!(keyState[(unsigned char)'a']) && !(keyState[(unsigned char)'d']))
	{
		player->Stop();
	}
}
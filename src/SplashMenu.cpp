#include "SplashMenu.h"

#define SERPILICUM_MODE_ROTATE

SplashMenu::SplashMenu(int pid, AbstractConsole* console, ActionListener * quitListener, int resourceID) : DisplayImageTextMenu(pid, console, quitListener, resourceID, 0)
{
	startTime = console->getCurrentTimeMillis();
}

void SplashMenu::render(AbstractConsole* pConsole) {
	double perc = 1;

	double delta = (pConsole->getCurrentTimeMillis() - startTime) / 60.0;

	for (int xx = 0; xx < BUFFER_W; xx++)
	{
		for (int yy = 0; yy < BUFFER_H; yy++)
		{
			double px = xx;
			double py = (BUFFER_H - yy - 1);

			if (yy > 8) {
				py += sin((xx + delta)/1.5) * 2.0;
				
				pConsole->write((resourceArray[yy * BUFFER_W + xx]) ? ('#') : (' '), (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
			} else {
#ifdef SERPILICUM_MODE_ROTATE
				px = BUFFER_W/2 - px;
				px *= -abs(sin(delta / 20.0));
				px = BUFFER_W/2 + px;
				py--;
#else
				px = (int)(px + delta*2) % BUFFER_W;
				py += (sin(((px*1.0) / BUFFER_W) * 2 * 3.14159) + 1) * -2;
#endif

				pConsole->write((resourceArray[yy * BUFFER_W + xx]) ? ('#') : (' '), (int)std::floor(px + 0.5), (int)std::floor(py + 0.5));
			}

			
		}
	}
}
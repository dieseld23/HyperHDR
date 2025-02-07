/* Animation_RainbowWaves.cpp
*
*  MIT License
*
*  Copyright (c) 2023 awawa-dev
*
*  Project homesite: https://github.com/awawa-dev/HyperHDR
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.

*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
 */

#include <effectengine/Animation_RainbowWaves.h>

Animation_RainbowWaves::Animation_RainbowWaves(QString name) :
	AnimationBase(name)
{
	SetSleepTime(100);
	hue = 0;
};



void Animation_RainbowWaves::Init(
	QImage& hyperImage,
	int hyperLatchTime
)
{

}

bool Animation_RainbowWaves::Play(QPainter* painter)
{
	return true;
}

bool Animation_RainbowWaves::hasLedData(QVector<ColorRgb>& buffer)
{
	if (buffer.length() > 0)
	{
		ColorRgb newColor{ 0,0,0 };
		ColorSys::hsv2rgb(hue, 255, 255, newColor.red, newColor.green, newColor.blue);

		if (++hue > 359)
			hue = 0;

		for (int i = 0; i < buffer.length(); i++)
		{
			buffer[i] = newColor;
		}
	}

	return true;
}

EffectDefinition Animation_RainbowWaves::getDefinition()
{
	EffectDefinition ed;
	ed.name = ANIM_RAINBOW_WAVES;
	ed.args = GetArgs();
	return ed;
}

QJsonObject Animation_RainbowWaves::GetArgs() {
	QJsonObject doc;
	doc["smoothing-custom-settings"] = false;
	return doc;
}



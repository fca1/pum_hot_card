//INTELLECTUAL AND INDUSTRIAL PROPERTY RIGHTS
//
// EPI ,E.U..R.L has the intellectual and industrial property rights of URL and source code, algorithm and binay.
// These rights protect graphic designs, source code, content and other elements of these code source,
// with the exception of property rights that are not owned by EPI and are owned by their respective owners.//
// EPI allows simple download and storage information of its depot in user's hard drive,
// but it is strictly prohibited to modify, distribute, reuse, or forward all or part of EPI's content
// for public or commercial purposes without EPIâ€™s written authorization.
//
// Actions that could infringe terms expressed above may constitute an infringement of the intellectual property
// protection rights in the consolidated text of the Intellectual Property Law (TRLPI),
// provoking lawsuits established in Articles to current Penal Code.

#include <chauffage/misc/g_circularByte.h>
#include <stdio.h>

void circularInit(struct t_rotary_byte *ptrBuffer)
{
ptrBuffer->indexW = ptrBuffer->indexR = 0;
}

uint8_t circularPush(struct t_rotary_byte *ptrBuffer, uint8_t obj)
{
uint8_t indexW = (ptrBuffer->indexW + 1) % (1 << POWER_ROTARY_BYTE);
if (indexW == ptrBuffer->indexR)
	return 0;
ptrBuffer->buffer[indexW] = obj;
ptrBuffer->indexW++;
return !0;
}

uint8_t circularGetLen(const struct t_rotary_byte *ptrBuffer)
{
if (ptrBuffer->indexW >= ptrBuffer->indexR)
	{
	return ptrBuffer->indexW - ptrBuffer->indexR;
	}
else
	{
	return ((1 << POWER_ROTARY_BYTE)) - ptrBuffer->indexR + ptrBuffer->indexW;
	}
}

uint8_t * circularPop(struct t_rotary_byte *ptrBuffer)
{
if (ptrBuffer->indexR == ptrBuffer->indexW)
	{
	return NULL;    // N'importe quelle valeur convient... normalement c'est une exception.
	}
return &(ptrBuffer->buffer[++ptrBuffer->indexR]);
}



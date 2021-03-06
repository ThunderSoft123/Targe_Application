/**
 ******************************************************************************
 * @file    Switch.h
 * @author  AST / EST
 * @version V0.0.1
 * @date    14-April-2015
 * @brief   Header file for red switch
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
*/


#ifndef __SWITCH_H
#define __SWITCH_H


/* Includes ------------------------------------------------------------------*/

#include "mbed.h"
#include "STMPE1600.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RANGE = 0,
    ALS
} SwitchState;


/* Classes -------------------------------------------------------------------*/

/**
 * Class representing Red Switch
 */ 
 
class Switch
{
public:
	Switch(STMPE1600 &stmpe_1600, exp_gpio_pin_name Pin_Name=GPIO_11) : stmpe1600(stmpe_1600), PinName(Pin_Name) {
		stmpe1600.set_gpio_dir(PinName, INPUT);
	}
 
	bool rd_switch () {
	    return stmpe1600.rd_gpio(PinName);
	}
			
    operator int() {
        return rd_switch();
    }		
		
 private:
		STMPE1600 &stmpe1600;
		exp_gpio_pin_name PinName;
};

#ifdef __cplusplus
}
#endif
#endif // __SWITCH_H

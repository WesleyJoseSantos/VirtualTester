/**
 * @file OverrideFunctions.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __OVERRIDEFUNCTIONS__H__
#define __OVERRIDEFUNCTIONS__H__

/**
 * @brief Overwriting arduino common hardware funcions declarations
 * 
 */
#define pinMode pinModeFunction
#define digitalRead digitalReadFunction
#define digitalWrite digitalWriteFunction
#define analogRead analogReadFunction
#define analogWrite analogWriteFunction
#define delay delayFunction

#endif  //!__OVERRIDEFUNCTIONS__H__
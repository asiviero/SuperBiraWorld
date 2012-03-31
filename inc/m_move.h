/*
 * m_move.h
 *
 *  Created on: Mar 30, 2012
 *      Author: andre
 */

#ifndef M_MOVE_H_
#define M_MOVE_H_

class m_move {
	enum _moveState {
	    MS_STOP,
	    MS_UP,
	    MS_LEFT,
	    MS_RIGHT,
	  };
public:
	int m_state[2];
	m_move();
};

#endif /* M_MOVE_H_ */

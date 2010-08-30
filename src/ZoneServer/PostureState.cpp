/*
---------------------------------------------------------------------------------------
This source file is part of SWG:ANH (Star Wars Galaxies - A New Hope - Server Emulator)

For more information, visit http://www.swganh.com

Copyright (c) 2006 - 2010 The SWG:ANH Team
---------------------------------------------------------------------------------------
Use of this source code is governed by the GPL v3 license that can be found
in the COPYING file or at http://www.gnu.org/licenses/gpl-3.0.html

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------
*/

#include "PostureState.h"


PostureState::PostureState(void)
{
    mStateID = 0;
    mTransitionList.clear();
}

PostureState::~PostureState(void)
{
    mStateID = 0;
    mTransitionList.clear();
}

void PostureState::Enter(CreatureObject* obj)
{
    obj->setPosture(mStateID);
}
void PostureState::Exit(CreatureObject* obj)
{
    obj->setPosture(0);
}
bool PostureState::CanTransition(uint64 newPosture)
{
    // check to see if the layer is blocked
    if (mBlocked)
        return false;
    transitionList::iterator itPosture = mTransitionList.find(State_Posture);
    transitionList::iterator itAction = mTransitionList.find(State_Action);
    transitionList::iterator itLocomotion = mTransitionList.find(State_Locomotion);
    // check each state type
    if (itPosture != mTransitionList.end())
    {
        // check the bitmask to see if we're allowed
        uint32 bitmask = itPosture->second;
        if((newPosture & bitmask) == 0)
            return false;
    }
    else if (itAction != mTransitionList.end())
    {
        // check the bitmask to see if we're allowed
        uint32 bitmask = itAction->second;
        if((newPosture & bitmask) != 0)
            return false;
    }
    else if (itLocomotion != mTransitionList.end())
    {
        // check the bitmask to see if we're allowed
        uint32 bitmask = itLocomotion->second;
        if((newPosture & bitmask) != 0)
            return false;
    }

    return true;
}

PostureUpright::PostureUpright() : PostureState()
{
    mStateID = CreaturePosture_Upright;
    
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Posture,5055));
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Action,3894542336));
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Locomotion,1783808));
}

bool PostureUpright::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Crouched
PostureCrouched::PostureCrouched() : PostureState()
{
    mStateID = CreaturePosture_Crouched;
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Posture,4415));
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Action,3894804480));
}

bool PostureCrouched::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Prone
PostureProne::PostureProne() : PostureState()
{
    mStateID = CreaturePosture_Prone;
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Posture,4415));
    mTransitionList.insert(std::pair<StateTypes, uint64>(State_Action,3894804480));
}

bool PostureProne::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Sneaking
PostureSneaking::PostureSneaking() : PostureState()
{
    mStateID = CreaturePosture_Sneaking;
}

bool PostureSneaking::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Blocking
PostureBlocking::PostureBlocking() : PostureState()
{
    mStateID = CreaturePosture_Blocking;
}

bool PostureBlocking::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Climbing
PostureClimbing::PostureClimbing() : PostureState()
{
    mStateID = CreaturePosture_Climbing;
}

bool PostureClimbing::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Flying
PostureFlying::PostureFlying() : PostureState()
{
    mStateID = CreaturePosture_Flying;
}

bool PostureFlying::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Lying Down
PostureLyingDown::PostureLyingDown() : PostureState()
{
    mStateID = CreaturePosture_LyingDown;
}

bool PostureLyingDown::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Sitting
PostureSitting::PostureSitting() : PostureState()
{
    mStateID = CreaturePosture_Sitting;
}

bool PostureSitting::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Skill Animating
PostureSkillAnimating::PostureSkillAnimating() : PostureState()
{
    mStateID = CreaturePosture_SkillAnimating;
}

bool PostureSkillAnimating::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Driving Vehicle
PostureDrivingVehicle::PostureDrivingVehicle() : PostureState()
{
    mStateID = CreaturePosture_DrivingVehicle;
}

bool PostureDrivingVehicle::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Riding Creature
PostureRidingCreature::PostureRidingCreature() : PostureState()
{
    mStateID = CreaturePosture_RidingCreature;
}

bool PostureRidingCreature::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Knocked Down
PostureKnockedDown::PostureKnockedDown() : PostureState()
{
    mStateID = CreaturePosture_KnockedDown;
}

bool PostureKnockedDown::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Incapacitated
PostureIncapacitated::PostureIncapacitated() : PostureState()
{
    mStateID = CreaturePosture_Incapacitated;
}

bool PostureIncapacitated::CanTransition(uint64 newPosture)
{
    return true;
}
//	Posture Dead
PostureDead::PostureDead() : PostureState()
{
    mStateID = CreaturePosture_Dead;
}
bool PostureDead::CanTransition(uint64 newPosture)
{
    return true;
}
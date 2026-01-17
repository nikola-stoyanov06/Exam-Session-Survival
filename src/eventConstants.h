/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Nikola Stoyanov
* @idnumber 3MI0600561* @compiler VC
*
* <file with random event data>
*
*/

#ifndef EVENTCONSTANTS_H
#define EVENTCONSTANTS_H
#include "constants.h"

const RandomEvent GOOD_EVENTS[] =
{
    { 1, 1, 0, 0, 10, 5, "Good lecture! The professor cracked jokes, you understood everything!" },
    { 1, 2, 0, 0, 0, 15, "You gave ChatGPT the perfect prompt. He explained, you understood." },
    { 1, 3, 0, 0, 5, 10, "Monkey together strong – breakthrough!" },
    { 1, 4, 20, 0, 10, 0, "Influencer walked in, paid for everyone who was subscribed to him (You were)." },
    { 2, 1, 0, 5, 15, 0, "You put an egg inside the ramen. You felt practically korean." },
    { 2, 2, 0, 10, 10, 0, "You found a dirty, smelly doner shop, but the doner is legendary." },
    { 2, 3, 0, 10, 5, 0, "There are 17 wings, not 14! How lucky!" },
    { 3, 1, 0, 10, 5, 0, "The lady gave you an extra meatball!" },
    { 3, 2, 0, 5, 0, 15, "That movie was absolutely live-changing! What a masterpiece!" },
    { 3, 3, 35, 0, 0, 0, "That one rich friend decided to cover the bill!" },
    { 4, 1, 0, 15, 10, 0, "That was the best nap of your life!" },
    { 4, 2, 0, 0, 15, -5, "You sent bro a funny vid and he hearted it immediately." },
    { 4, 3, 0, 20, 10, 0, "It was raining outside. The room was cold. The perfect sleep awaited." },
    { 5, 1, 0, 0, 15, 0, "That dumb kid laughed at your stupid joke and made you happy." },
    { 5, 2, 15, 0, 10, 5, "The customer promised to recommend you. More clients called!" },
    { 5, 3, 0, 15, 10, 0, "Glovo guy never came. Five big macs left for you." }
};



const RandomEvent BAD_EVENTS[] =
{
    { 1, 1, 0, -5, 0, -10, "Bus 94 never came. Someone jumped on the metro rails. You missed half the lecture." },
    { 1, 2, 0, 0, -10, -15, "You ended up watching reels all day." },
    { 1, 3, 0, -15, -5, -5, "You told yourself you all will study. You ended up at Illusion" },
    { 1, 4, 0, 0, -15, 0, "You got called performative for ordering matcha." },
    { 2, 1, 0, -25, -10, 0, "That spicy Buldak ramen was too much for your stomach." },
    { 2, 2, 0, -25, -10, 0, "It turns out the doner man last washed his hands in `07." },
    { 2, 3, 0, -25, -15, 0, "You choked on a bone." },
    { 3, 1, 0, 0, -20, 0, "They ran out of kebapcheta!" },
    { 3, 2, 0, -5, -15, 0, "The kid behind screamed and kicked all movie long." },
    { 3, 3, -10, -35, -15, -10, "You blacked out!" },
    { 4, 1, 0, 10, -5, -15, "A five-min nap lasted five hours." },
    { 4, 2, 0, 0, 0, -25, "You are now severely brainrotted." },
    { 4, 3, 0, -15, -15, -5, "The neighbour started drilling at 5 am." },
    { 5, 1, -20, -5, -5, -5, "That dumb kid got you into trouble. His mom refused to pay." },
    { 5, 2, -20, -10, -10, -5, "You did the job. Customer sent a middle finger and blocked you." },
    { 5, 3, 0, -15, -20, -10, "You had to argue with a client, unhappy that his cheeseburger had cheese." }
};

#endif
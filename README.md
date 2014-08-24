ECS
===

Game Engine Based on Entity Component System.

This is one of many attempts at making a game engine in C.

This game engine specifically uses a 'Component based Entity System.'

The App (or game) will be composed of managers (Event Manager, Scene Manager,
RenderManager, etc).

Each Manager will be composed of Entities (Player, Enemy, Camera,
any game object, etc) and Subsystems (Event Subsystem, Movement Subsystem,
Transformation Subsystem, etc).

So far, this is what the Composition Heirarchy is supposed to look like:


        App:
            Event Manager:
                Keyboard Subsystem,   // Gets the state of the keyboard.
                Mouse    Subsystem,   // Gets the state of the mouse.
                
                Keybaord Entity,      // Holds the state of the keyboard.
                Mouse    Entity,      // Holds the state of the mouse.
                                      
            Scene Manager:
                Event    Subsystem,   // Gets the state of keyboard and mouse sends
                                      // appropriate events to each Entity depending 
                                      // on which Entity registered for which event.
                Movement Subsystem,
                Leveling Subsystem,
                ...                   // Probably many more subsystems.
                
                Event    Entities,    // These are just event objects containing 
                                      // different types of information, depending 
                                      // on the event type. Each event is derived from 
                                      // an Event struct.
                
                Game     Entities[]   // Like player, enemies, door, etc.
                                      // All derived from the entity struct.
                                      // All have a dynamic array to hold events
                                      // (like a mailbox) sent from the Event 
                                      // Subsystem.
                                      
            Render Manager:
                Render   Subsystem,   // Gets all objects that need to be rendered from 
                                      // the Scene Manager.
                                      
                Renderer Entity       // With information like Window Size and
                                      // probably references to SDL_Window and
                                      // SDL_Renderer.

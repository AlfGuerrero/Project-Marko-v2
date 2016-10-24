/*
Alfrancis Guerrero - 09/20/16
Add this class to what you want to measure your intial object. AKA The users position. 
*/

using UnityEngine;
using System.Collections;

public class raycastForward : MonoBehaviour {
	
	void Update () {
		RaycastHit hit;
		float theDistance;
		Vector3 forward = transform.TransformDirection(Vector3.forward) * 10; //10 meters
		// Debug Raycast in the Editor - SO WE CAN SEE IT! 

		Debug.DrawRay(transform.position, forward, Color.green);

		if(Physics.Raycast(transform.position,(forward), out hit)){
			theDistance = hit.distance; //Distance how far we hit

			Debug.Log("DISTANCE HIT: "+theDistance + " " + "hit.collider.gameObject.name");
		}
	}
}

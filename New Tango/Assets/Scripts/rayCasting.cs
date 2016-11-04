using UnityEngine;
using System.Collections;

public class rayCasting : MonoBehaviour {
	GameObject m_cube;


	RaycastHit hit; 

	float theDistance;
	void start(){
	}
	// Update is called once per frame
	void Update () {


		Vector3 forward = transform.TransformDirection(Vector3.forward) * 10; //10 meters

		Debug.DrawRay(transform.position, forward, Color.green);
		m_cube = GameObject.FindGameObjectWithTag ("cubes");
		if(Physics.Raycast(transform.position,(forward), out hit)){
			
			theDistance = hit.distance; //Distance how far we hit
			m_cube.transform.position = hit.point;
			//Instantiate( m_cube , hit.point, Quaternion.identity);
			//m_cube.transform.position += transform.forward * hit.distance;

			Debug.Log("DISTANCE HIT: " +theDistance + " " + "hit.collider.gameObject.name");
			Debug.Log("CUBE HIT: " + m_cube.transform.position.ToString() + " " + "hit.collider.gameObject.name");
			Debug.Log("HIT HIT: " + hit.point.ToString() + " " + "hit.collider.gameObject.name");
		}
	}

	void OnGUI() {
		GUI.color = Color.black;
		GUI.skin.label.fontSize = 30;		
		GUI.Label (new Rect(40, 220, 400, 200),"Magnitude: " + theDistance.ToString() + " m");
		GUI.Label (new Rect(40, 260, 400, 200), "Tablet V1: " + transform.position.ToString() );
		GUI.Label (new Rect(40, 300, 400, 200), "RayCasts V2: " + hit.point.ToString() );
		GUI.Label (new Rect(40, 340, 400, 200), "Cube (V2): " + m_cube.transform.position.ToString());


	}
}

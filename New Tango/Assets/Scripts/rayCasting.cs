using UnityEngine;
using System.Collections;

public class rayCasting : MonoBehaviour {
	GameObject m_cube;

	//public string meshName = "Nothing";

	RaycastHit[] middleHit = new RaycastHit[8]; 
	RaycastHit[] topHit = new RaycastHit[8];
	RaycastHit[] bottomHit = new RaycastHit[8];
	//RaycastHit[] f = Physics.RaycastAll(transform.position, transform, forward, 50);


	float theDistance;
	void start(){


	}
	// Update is called once per frame
	void Update () {

		for (int i = 0; i < 8; i++) {
			//Quaternion rotation = Quaternion.AngleAxis (45.0f, transform.right);
			Quaternion q = Quaternion.AngleAxis(45*i, Vector3.up);
			Vector3  d = transform.forward *20;

			Debug.DrawRay(transform.position, q*d, Color.green);
			//m_cube = GameObject.FindGameObjectWithTag ("cubes");
			if(Physics.Raycast(transform.position,q*d, out middleHit[i])){
				//Quaternion.AngleAxis(20, transform.up) * transform.forward
				theDistance = middleHit[i].distance; //Distance how far we hit

				m_cube = GameObject.Find("Cube_"+i);
				m_cube.transform.position = middleHit[i].point;
				//Instantiate( m_cube , hit.point, Quaternion.identity);
				//m_cube.transform.position += transform.forward * hit.distance;

				//Debug.Log("DISTANCE HIT: " +theDistance + " " + "hit.collider.gameObject.name");
				//Debug.Log("CUBE HIT: " + m_cube.transform.position.ToString() + " " + "hit.collider.gameObject.name");
				//Debug.Log("HIT HIT: " + hit.point.ToString() + " " + "hit.collider.gameObject.name");
			}

		}


		//Vector3 forward = transform.TransformDirection(Vector3.forward) * 10; //10 meters


	}

	void OnGUI() {
		GUI.color = Color.black;
		GUI.skin.label.fontSize = 30;		
		GUI.Label (new Rect(40, 220, 400, 200),"Magnitude: " + theDistance.ToString() + " m");
		GUI.Label (new Rect(40, 260, 400, 200), "Tablet V1: " + transform.position.ToString() );
		//GUI.Label (new Rect(40, 300, 400, 200), "RayCasts V2: " + middleHit.point.ToString() );
		GUI.Label (new Rect(40, 340, 400, 200), "Cube (V2): " + m_cube.transform.position.ToString());
		GUI.Label(new Rect(40, 380, 100, 200), GameObject.Find("Tango Manager").GetComponent<MeshLoader>().meshName);


	}
}

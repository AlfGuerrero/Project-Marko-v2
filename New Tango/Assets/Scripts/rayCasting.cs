using UnityEngine;
using System.Collections;

public class rayCasting : MonoBehaviour {
	GameObject m_cube;
	GameObject m_cube2;
	GameObject m_cube3;

	//public string meshName = "Nothing";


	RaycastHit[] middleHit = new RaycastHit[8]; 
	RaycastHit[] topHit = new RaycastHit[8];
	RaycastHit[] bottomHit = new RaycastHit[8];
	//RaycastHit[] f = Physics.RaycastAll(transform.position, transform, forward, 50);


	//float[] middleDistance;
	//float[] topDistance;
	//float[] bottomDistance;

	float[] closestDist;
	public int[] vibHeight;


	void Start(){
		
		//topDistance = new float[8];
		//middleDistance = new float[8];
		//bottomDistance = new float[8];
		closestDist = new float[8];
		vibHeight = new int[8];

		for (int i = 0; i < 8; i++) {
			//topDistance [i] = 0;
			//middleDistance [i] = 0;
			//bottomDistance [i] = 0;
			closestDist [i] = 0;
			vibHeight [i] = 0;
		}

		GameObject.Find("BtConnector").GetComponent<BluetoothSender>().connect();

	}
	// Update is called once per frame
	void Update () {

		//reset distances to avoid frozen distances when depth is lost
		for (int i = 0; i < 8; i++) {
			//topDistance [i] = 0;
			//middleDistance [i] = 0;
			//bottomDistance [i] = 0;
			closestDist [i] = 6;
			vibHeight [i] = 0;
		}

		//raycast high, low, medium and move cube to intersection point with mesh
		for (int i = 0; i < 8; i++) {
			//Quaternion rotation = Quaternion.AngleAxis (45.0f, transform.right);
			Quaternion q = Quaternion.AngleAxis(45*i, Vector3.up);
			//Quaternion q2= Quaternion.AngleAxis(65*i, Vector3.up);
			//Quaternion q3 = Quaternion.AngleAxis(65*i, Vector3.up);

			Vector3  d = new Vector3(transform.forward.x,0.0f,transform.forward.z) *20;
			Vector3  d2 = new Vector3(transform.forward.x,-0.5f,transform.forward.z) *20;
			Vector3  d3 = new Vector3(transform.forward.x,0.5f,transform.forward.z) *20;

			Debug.DrawRay(transform.position, q*d, Color.green);
			Debug.DrawRay(transform.position, q*d2, Color.red);
			Debug.DrawRay(transform.position, q*d3, Color.blue);

			//BOTTOM
			if (Physics.Raycast (transform.position, q * d3, out bottomHit [i])) {
				//Quaternion.AngleAxis(20, transform.up) * transform.forward
				//bottomDistance[i] = bottomHit[i].distance; //Distance how far we hit
				//if (bottomHit [i].distance < closestDist [i]) {
					//closestDist [i] = bottomHit [i].distance; //Distance how far we hit
				//}
				if (bottomHit [i].distance <= 5.0f) {
					//GetComponent<Vibration> ().vibLevel [i] = 255 - Map (topDistance [i], 0, 255, 0, 5);
					vibHeight [i] += 1;
				} 


				m_cube3 = GameObject.Find ("lowerCube_" + i);
				m_cube3.transform.position = bottomHit [i].point;
				//Instantiate( m_cube , hit.point, Quaternion.identity);
				//m_cube.transform.position += transform.forward * hit.distance;

				//Debug.Log("DISTANCE HIT: " +theDistance + " " + "hit.collider.gameObject.name");
				//Debug.Log("CUBE HIT: " + m_cube.transform.position.ToString() + " " + "hit.collider.gameObject.name");
				//Debug.Log("HIT HIT: " + hit.point.ToString() + " " + "hit.collider.gameObject.name");
			} else {
				closestDist [i] = 6;
			}

			//MIDDLE
			if(Physics.Raycast(transform.position,q*d2, out middleHit[i])){
				//Quaternion.AngleAxis(20, transform.up) * transform.forward
				//middleDistance[i] = middleHit[i].distance; //Distance how far we hit
				//if (middleHit [i].distance < closestDist [i]) {
					//closestDist[i] = middleHit[i].distance; //Distance how far we hit
				GameObject.Find("Tango Manager").GetComponent<Vibration> ().vibLevel [i] = middleHit[i].distance;
				//GameObject.Find ("BTConnector").GetComponent<BluetoothSender> ().Update ();

				//}
				if (middleHit [i].distance <= 5.0f) {
					//GetComponent<Vibration> ().vibLevel [i] = 255 - Map (topDistance [i], 0, 255, 0, 5);
					vibHeight[i] += 1;
				} 

				m_cube = GameObject.Find("Cube_"+i);
				m_cube.transform.position = middleHit[i].point;
				//Instantiate( m_cube , hit.point, Quaternion.identity);
				//m_cube.transform.position += transform.forward * hit.distance;

				//Debug.Log("DISTANCE HIT: " +theDistance + " " + "hit.collider.gameObject.name");
				//Debug.Log("CUBE HIT: " + m_cube.transform.position.ToString() + " " + "hit.collider.gameObject.name");
				//Debug.Log("HIT HIT: " + hit.point.ToString() + " " + "hit.collider.gameObject.name");
			}

			if(Physics.Raycast(transform.position,q*d, out topHit[i])){
				//Quaternion.AngleAxis(20, transform.up) * transform.forward
				//if(i==0)
				//{
				//middleDistance[i] = middleHit[i].distance; //Distance how far we hit

				if (topHit [i].distance < closestDist [i]) {
					//closestDist[i] = topHit[i].distance; //Distance how far we hit
				}

				if (topHit [i].distance <= 5.0f) {
					//GetComponent<Vibration> ().vibLevel [i] = 255 - Map (topDistance [i], 0, 255, 0, 5);
					vibHeight[i] += 1;
				} 
				//bottomDistance[i] = bottomHit[i].distance; //Distance how far we hit
				//}

				m_cube2 = GameObject.Find("upperCube_"+i);
				m_cube2.transform.position = topHit[i].point;
				//Instantiate( m_cube , hit.point, Quaternion.identity);
				//m_cube.transform.position += transform.forward * hit.distance;

				//Debug.Log("DISTANCE HIT: " +theDistance + " " + "hit.collider.gameObject.name");
				//Debug.Log("CUBE HIT: " + m_cube.transform.position.ToString() + " " + "hit.collider.gameObject.name");
				//Debug.Log("HIT HIT: " + hit.point.ToString() + " " + "hit.collider.gameObject.name");


			}
			GameObject.Find("Tango Manager").GetComponent<Vibration> ().vibHeight [i] = vibHeight[i];
			//GameObject.Find("Tango Manager").GetComponent<Vibration> ().vibLevel [i] = closestDist[i];

		}



		
			//GameObject.Find("BtConnector").GetComponent<BluetoothSender>().SendData(GetComponent<Vibration> ().vibLevel);

	}

	//Map the value for Arduino
	//public double Map(double value, double in_min, double in_max, double out_min, double out_max){
		//return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; 
	//}

	void OnGUI() {
		GUI.color = Color.black;
		GUI.skin.label.fontSize = 30;		
		//GUI.Label (new Rect(40, 220, 400, 200),"Magnitude: " + theDistance.ToString() + " m");
		GUI.Label (new Rect(40, 260, 400, 200), "Tablet V1: " + transform.position.ToString() );
		//GUI.Label (new Rect(40, 300, 400, 200), "RayCasts V2: " + middleHit.point.ToString() );
		//GUI.Label (new Rect(40, 340, 400, 200), "Cube (V2): " + m_cube.transform.position.ToString());
		GUI.Label(new Rect(40, 380, 100, 200), GameObject.Find("Tango Manager").GetComponent<MeshLoader>().meshName);

		for (int i = 0; i < 8; i++) {
			GUI.Label (new Rect(40, 400+(40*i), 600, 200)," Closest Magnitude: " + GameObject.Find("Tango Manager").GetComponent<Vibration> ().vibLevel [i].ToString("f3") + " m");
		}
		//for (int i = 0; i < 8; i++) {
		//GUI.Label (new Rect(440, 400+(40*i), 400, 200)," Middle Magnitude: " + middleDistance[i].ToString() + " m");
		//}
		//for (int i = 0; i < 8; i++) {
		//GUI.Label (new Rect(880, 400+(40*i), 400, 200)," Bottom Magnitude: " + bottomDistance[i].ToString() + " m");
		//}


	}
}
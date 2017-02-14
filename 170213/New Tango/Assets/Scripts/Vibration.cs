using UnityEngine;
using System.Collections;


public class Vibration : MonoBehaviour {

	public float[] vibLevel;
	public int[] vibHeight;

	// Use this for initialization
	void Start () {
		vibLevel = new float[8];
		vibHeight = new int[8];

		for (int i = 0; i < 8; i++) {
			vibLevel[i] = 6.0f;
		}
		for (int i = 0; i < 8; i++) {
			vibHeight[i] = 0;
		}

	}

	// Update is called once per frame
	void Update () {

		for (int i = 0; i<8; i++){
			//vibLevel [i] = GetComponent<rayCasting> ().vibHeight [i];
		}



	}



}